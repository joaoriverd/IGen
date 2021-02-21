import re
import subprocess
import os
import sys
from argparse import ArgumentParser
from pathlib import Path

# Configuration
debug = False

# Regular expressions
rex_include           = r'#[\s]*include[\s]*[<"].*[>"]'
rex_include_directive = r'#[\s]*include[\s]*'
rex_immintrin         = r'#[\s]*include[\s]*[<"]immintrin.h[>"]]?'
rex_math_h            = r'#[\s]*include[\s]*[<"]math.h[>"]]?'

# IGen header files
igen_immintrin        = '#include "igen_immintrin.h"'
igen_dd_immintrin     = '#include "igen_dd_immintrin.h"'
igen_prep_immintrin   = '#include "igen_prep_immintrin.h"'
# igen_math_h           = '#include "igen_math.h"'
# igen_dd_math_h        = '#include "igen_dd_math.h"'

# Paths
project_path       = Path(os.path.dirname(os.path.abspath(__file__))).parent
igen_lib_path      = os.path.join(project_path, 'igen_lib')
clang_include_path = os.path.join(project_path, 'third-party/llvm-project-11.0.1/install/lib/clang/11.0.1/include')
clang_bin_path     = os.path.join(project_path, 'third-party/llvm-project-11.0.1/install/bin')

# Binaries
igen_bin           = os.path.join(project_path, 'bin/igen')
clang_bin          = os.path.join(clang_bin_path, 'clang')
opt_bin            = os.path.join(clang_bin_path, 'opt')
tidy_bin           = os.path.join(clang_bin_path, 'clang-tidy')
format_bin         = os.path.join(clang_bin_path, 'clang-format')

# File's names
prep_file_name        = '__prep.c'
polly_redu_file_name  = '__redu.csv'

std_headers = [
    'assert.h',
    'complex.h',
    'ctype.h',
    'errno.h',
    'fenv.h',
    'float.h',
    'inttypes.h',
    'iso646.h',
    'limits.h',
    'locale.h',
    'math.h',
    'setjmp.h',
    'signal.h',
    'stdalign.h',
    'stdarg.h',
    'stdatomic.h',
    'stdbool.h',
    'stddef.h',
    'stdint.h',
    'stdio.h',
    'stdlib.h',
    'stdnoreturn.h',
    'string.h',
    'tgmath.h',
    'threads.h',
    'time.h',
    'uchar.h',
    'wchar.h',
    'wctype.h',
    # custome
    'igen_prep_immintrin.h',
    'immintrin.h'
]


def run_command(cmd):
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    out, err = p.communicate()
    return out.decode("utf-8"), err.decode("utf-8")


def is_standard_header(header):
    if header.startswith('<') and header.endswith('>'):
        return True
    if header.startswith('"') and header.endswith('"'):
        file = header[1:-1]
        if file in std_headers:
            return True
    return False


# Return a list of the used standard header files by input file.
def get_used_std_headers(args):
    # Call clang preprocessor to find out the header call tree
    cmd = [clang_bin, "-M", "-H", args.input_file, '-I' + igen_lib_path]
    if args.includes is not None:
        for i in args.includes:
            cmd += ['-I' + i]
    if args.defines is not None:
        for i in args.defines:
            cmd += ['-D' + i]
    out, err = run_command(cmd)
    headers_raw = err

    std_headers_list = []
    for h in std_headers:
        if '/' + h in headers_raw:
            std_headers_list += [h]

    return std_headers_list


def run_preprocessor(args):
    print('Starting preprocessor:')
    print("\tWrapping #include's")
    if os.path.dirname(args.input_file) == '':
        prep_file = './' + prep_file_name
    else:
        prep_file = os.path.dirname(args.input_file) + '/' + prep_file_name

    finp = open(args.input_file, "rt")
    fout = open(prep_file, "wt")

    # First include the used header files in the prep file with annotation if required
    if args.prep_headers:
        std_headers_list = get_used_std_headers(args)
        for h in std_headers_list:
            h = '<' + h + '>'

            # Replace the header file for intrinsics if required.
            if h == '<immintrin.h>':
                h = '"igen_prep_immintrin.h"'

            new_line = '<include> ' + h + '\n#include ' + h + '\n</include> ' + h + '\n'
            fout.write(new_line)

    # Find and annotate all #include directives (enclose them with <include> and <\include>)
    for line in finp:
        new_line = line
        match = re.findall(rex_include, line)

        if len(match) > 0 and not args.prep_headers:
            # Wrap include file
            include_line = match[0]
            include_text = re.sub(rex_immintrin, igen_prep_immintrin, include_line)
            header_file = re.sub(rex_include_directive, '', include_text)
            # Annotate all files if user doesn't want to preprocess header files
            new_line = re.sub(include_line, '<include> ' + header_file + '\n' + include_text + '\n</include> ' + header_file, line)

        fout.write(new_line)
    fout.close()
    finp.close()

    print("\tCalling clang preprocessor")
    # Here we still have to call the preprocessor with comments enabled [-C], otherwise there
    # will be some extra </include> for #includes that are commented out. The comments will be
    # removed at the end.
    cmd = [clang_bin, "-E", "-P", "-C", prep_file, '-I' + igen_lib_path]
    if args.includes is not None:
        for i in args.includes:
            cmd += ['-I' + i]
    if args.defines is not None:
        for i in args.defines:
            cmd += ['-D' + i]
    prep_content, err = run_command(cmd)

    print("\tRestoring header files after preprocessing")
    prep_content = re.sub(r'<include>.*?</include>', '<include>', prep_content, 0, re.DOTALL)

    # Rerun preprocessor to remove the comments if required
    if args.with_comments is False:
        fout = open(prep_file, "wt")
        fout.write(prep_content)
        fout.close()
        cmd = [clang_bin, "-E", "-P", prep_file, '-I' + igen_lib_path]
        prep_content, err = run_command(cmd)

    # Change <include> to #include for the header files
    prep_content = re.sub('<include>', '#include', prep_content)

    fout = open(prep_file, "wt")
    fout.write(prep_content)
    fout.close()

    print("\tDone preprocessing")


def run_clang_tidy(args):
    if os.path.dirname(args.input_file) == '':
        prep_file = './' + prep_file_name
    else:
        prep_file = os.path.dirname(args.input_file) + '/' + prep_file_name
    # Run clang-tidy to fix braces around if statements.
    print("\tRunning clang-tidy to fix braces around if statements if needed")
    cmd = [tidy_bin, prep_file, '-fix', '-checks=readability-braces-around-statements',
           '--', '-I' + clang_include_path, '-I' + igen_lib_path]
    if args.includes is not None:
        for i in args.includes:
            cmd += ['-I' + i]
    if args.defines is not None:
        for i in args.defines:
            cmd += ['-D' + i]
    out, err = run_command(cmd)
    # print(out)


def run_clang_format(args):
    print('Running clang-format')
    cmd = [format_bin, args.output_file]
    igen_out, err = run_command(cmd)
    fout = open(args.output_file, "wt")
    fout.write(igen_out)
    fout.close()

# Reduction analysis is done by calling (our modified) polly. The following commands are executed:
# 1) clang __prep.c -S -emit-llvm -Xclang -disable-O0-optnone -o __ir.ll -g
# 2) opt   __ir.ll      -S -polly-canonicalize -o __ir.ll
# 3) opt   __ir.ll      -analyze -polly-dependences
def run_reduction_analysis(args):
    print('Starting reduction analysis:')
    print('\tGenerating IR')
    if os.path.dirname(args.input_file) == '':
        prep_file = './' + prep_file_name
        redu_file = './' + polly_redu_file_name
        IR_file   = './__ir.ll'
    else:
        prep_file = os.path.dirname(args.input_file) + '/' + prep_file_name
        redu_file = os.path.dirname(args.input_file) + '/' + polly_redu_file_name
        IR_file   = os.path.dirname(args.input_file) + '/__ir.ll'

    # Construct and run commands
    cmd1 = [clang_bin, prep_file, '-S', '-emit-llvm', '-Xclang', '-disable-O0-optnone', '-o', IR_file, '-g']
    if args.includes is not None:
        for i in args.includes:
            cmd1 += ['-I' + i]
    if args.defines is not None:
        for i in args.defines:
            cmd1 += ['-D' + i]
    run_command(cmd1)

    if not os.path.isfile(IR_file):
        print('\tError when analysing reductions. Skipping reduction analysis.')
        return

    # Opt commands (actual analysis)
    print('\tCalling polly on IR')
    cmd2 = [opt_bin  , IR_file  , '-S', '-polly-canonicalize', '-o', IR_file]
    cmd3 = [opt_bin  , IR_file  , '-analyze', '-polly-dependences', '-polly-process-unprofitable']
    run_command(cmd2)
    msg, redu = run_command(cmd3)
    os.remove(IR_file)

    # Print messages generated by polly
    if args.verbose:
        print(msg)
        print(redu)

    fredu = open(redu_file, "wt")
    fredu.write(redu)
    fredu.close()


def run_igen(args):
    print('Starting IGen tool:')
    print('\tRunning IGen')
    if os.path.dirname(args.input_file) == '':
        prep_file = './' + prep_file_name
        redu_file = './' + polly_redu_file_name
    else:
        prep_file = os.path.dirname(args.input_file) + '/' + prep_file_name
        redu_file = os.path.dirname(args.input_file) + '/' + polly_redu_file_name

    # Construct and run command
    cmd = [igen_bin, prep_file, '--', '-I' + clang_include_path, '-I' + igen_lib_path]
    if args.includes is not None:
        for i in args.includes:
            cmd += ['-I' + i]
    if args.defines is not None:
        for i in args.defines:
            cmd += ['-D' + i]
    cmd += ['-lib=' + args.interval_lib, '-tmode=' + args.tmode, redu_file]
    igen_out, igen_messages = run_command(cmd)
    os.remove(prep_file)

    print('\tReplacing header files')
    # igen_out = re.sub(rex_math_h, igen_math_h, igen_out)
    if args.tmode == "promote_dd":
        igen_out = re.sub(igen_prep_immintrin, igen_dd_immintrin, igen_out)
    else:
        igen_out = re.sub(igen_prep_immintrin, igen_immintrin, igen_out)
    fout = open(args.output_file, "wt")
    fout.write(igen_out)
    fout.close()

    # Removing reduction information
    if os.path.isfile(redu_file):
        os.remove(redu_file)

    # Print messages generated by igen
    if args.verbose:
        print(igen_messages)


def parse_arguments():
    parser = ArgumentParser()
    parser.add_argument('input_file', metavar='<input_file>', type=str,
                        help='specify input file')
    parser.add_argument('-o', dest='output_file', metavar='<output_file>',
                        help='specify name of output file')
    parser.add_argument('-lib', dest='interval_lib', default='igen', metavar='<interval_lib>',
                        help='specify interval library to use. E.g., igen, mpfi, boost')
    parser.add_argument('-tmode', dest='tmode', default='normal', metavar='<transform_mode>',
                        help='specify transformation mode to use. E.g., normal, promote_double, promote_dd')
    parser.add_argument('-I', dest='includes', metavar='<path>',
                        action='append', help='specify directories to include')
    parser.add_argument('-D', dest='defines', metavar='<define>',
                        action='append', help='specify definitions')
    parser.add_argument('-C', dest='with_comments',
                        action='store_true', default=False, help='preserve comments')
    parser.add_argument('-H', dest='prep_headers',
                        action='store_true', default=False,
                        help='preprocess local header files (standard library header files are not preprocessed)')
    parser.add_argument('-E', dest='only_preprocessor',
                        action='store_true', default=False,
                        help='Run only preprocessor phase')
    parser.add_argument('-V', dest='verbose',
                        action='store_true', default=False,
                        help='Print verbose information')

    args = parser.parse_args()

    if not os.path.exists(args.input_file):
        sys.exit('Error: Input file not found')

    # set default output file in case it is not specified
    if args.output_file is None:
        input_file_name = os.path.basename(args.input_file)
        input_path = os.path.dirname(args.input_file)
        if input_path == '':
            input_path = '.'
        args.output_file = input_path + '/igen_' + input_file_name

    if debug:
        print(args.input_file)
        print(args.output_file)
        print(args.interval_lib)
        print(args.tmode)
        print(args.includes)
        print(args.defines)
        print(args.with_comments)
        print(args.prep_headers)
        print(args.only_preprocessor)

    return args


if __name__ == "__main__":
    args = parse_arguments()
    run_preprocessor(args)
    if not args.only_preprocessor:
        run_clang_tidy(args)
        run_reduction_analysis(args)
        run_igen(args)
        run_clang_format(args)

    print('Done IGen')
