import os
import argparse

dirname   = os.path.dirname(os.path.abspath(__file__))
build_dir = os.path.join(dirname, "build")
install_dir = os.path.join(dirname, "install")

# Arguments
debug = False

def build():
    # Create building directory
    os.makedirs(build_dir, exist_ok=True)
    working_dir = os.getcwd()
    os.chdir(build_dir)

    build_type = "Debug" if debug else "Release"

    # Running CMake for IGen-vv and IGen-sv
    print('Generating build infrastructure for Clang:')
    cmake_options = '-DLLVM_ENABLE_PROJECTS="clang;polly" ' + \
                    '-DCMAKE_INSTALL_PREFIX=' + install_dir + ' ' + \
                    '-DCMAKE_BUILD_TYPE=' + build_type

    if debug:
        cmake_options += ' -DLLVM_OPTIMIZED_TABLEGEN=On'

    print(cmake_options)

    os.system('cmake ' + cmake_options + ' ../llvm')

    # Build project
    print("Building Clang:")
    # os.system("make")
    os.system("make install -j2")

    # Return to working directory before leave
    os.chdir(working_dir)

def parse_args():
    parser = argparse.ArgumentParser(description='Build clang, llvm and polly. The build type is "Release" by default.')
    parser.add_argument("-d", "--debug", help="Compile debug mode.", action="store_true")
    args = parser.parse_args()

    global debug
    debug = args.debug

if __name__ == "__main__":
    parse_args()
    build()
