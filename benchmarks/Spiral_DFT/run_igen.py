import os

dirname = os.path.dirname(__file__)
igen_script = os.path.join(dirname, '../../bin/igen.py')
args = [
    # IGen-sv
    {'inp':'spiral_source/DFT16.cpp' ,     'out':'igen/f64i_DFT16.cpp' ,     'mode':'normal'},
    {'inp':'spiral_source/DFT32.cpp' ,     'out':'igen/f64i_DFT32.cpp' ,     'mode':'normal'},
    {'inp':'spiral_source/DFT64.cpp' ,     'out':'igen/f64i_DFT64.cpp' ,     'mode':'normal'},
    {'inp':'spiral_source/DFT128.cpp',     'out':'igen/f64i_DFT128.cpp',     'mode':'normal'},
    {'inp':'spiral_source/DFT256.cpp',     'out':'igen/f64i_DFT256.cpp',     'mode':'normal'},

    # IGen-sv-dd
    {'inp':'spiral_source/DFT16.cpp' ,     'out':'igen/ddi_DFT16.cpp' ,     'mode':'promote_dd'},
    {'inp':'spiral_source/DFT32.cpp' ,     'out':'igen/ddi_DFT32.cpp' ,     'mode':'promote_dd'},
    {'inp':'spiral_source/DFT64.cpp' ,     'out':'igen/ddi_DFT64.cpp' ,     'mode':'promote_dd'},
    {'inp':'spiral_source/DFT128.cpp',     'out':'igen/ddi_DFT128.cpp',     'mode':'promote_dd'},
    {'inp':'spiral_source/DFT256.cpp',     'out':'igen/ddi_DFT256.cpp',     'mode':'promote_dd'},

    # IGen-vv
    {'inp':'spiral_source/AVX_DFT16.cpp' ,     'out':'igen/f64i_AVX_DFT16.cpp' ,     'mode':'normal'},
    {'inp':'spiral_source/AVX_DFT32.cpp' ,     'out':'igen/f64i_AVX_DFT32.cpp' ,     'mode':'normal'},
    {'inp':'spiral_source/AVX_DFT64.cpp' ,     'out':'igen/f64i_AVX_DFT64.cpp' ,     'mode':'normal'},
    {'inp':'spiral_source/AVX_DFT128.cpp',     'out':'igen/f64i_AVX_DFT128.cpp',     'mode':'normal'},
    {'inp':'spiral_source/AVX_DFT256.cpp',     'out':'igen/f64i_AVX_DFT256.cpp',     'mode':'normal'},

    # IGen-vv-dd
    {'inp':'spiral_source/AVX_DFT16.cpp' ,     'out':'igen/ddi_AVX_DFT16.cpp' ,     'mode':'promote_dd'},
    {'inp':'spiral_source/AVX_DFT32.cpp' ,     'out':'igen/ddi_AVX_DFT32.cpp' ,     'mode':'promote_dd'},
    {'inp':'spiral_source/AVX_DFT64.cpp' ,     'out':'igen/ddi_AVX_DFT64.cpp' ,     'mode':'promote_dd'},
    {'inp':'spiral_source/AVX_DFT128.cpp',     'out':'igen/ddi_AVX_DFT128.cpp',     'mode':'promote_dd'},
    {'inp':'spiral_source/AVX_DFT256.cpp',     'out':'igen/ddi_AVX_DFT256.cpp',     'mode':'promote_dd'},
]

def generate_igen_files():
    print("Generating IGen files for DFT benchmark:")
    dirname  = os.path.dirname(__file__)
    igen_dir = os.path.join(dirname, "igen")
    os.makedirs(igen_dir, exist_ok=True)
    for a in args:
        inp_file = os.path.join(dirname, a['inp'])
        out_file = os.path.join(dirname, a['out'])
        cmd = 'python ' + igen_script + " -H " + "-o " + out_file + " -tmode " + a['mode'] + " " + inp_file
        print(cmd)
        os.system(cmd)
        print("\n")


if __name__ == "__main__":
    generate_files()
