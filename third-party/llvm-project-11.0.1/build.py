import os

dirname   = os.path.dirname(os.path.abspath(__file__))
build_dir = os.path.join(dirname, "build")
install_dir = os.path.join(dirname, "install")

def build():
    # Create building directory
    os.makedirs(build_dir, exist_ok=True)
    working_dir = os.getcwd()
    os.chdir(build_dir)

    # Running CMake for IGen-vv and IGen-sv
    print('Generating build infrastructure for Clang:')
    cmake_options = '-DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra;polly" ' + \
                    '-DCMAKE_INSTALL_PREFIX=' + install_dir + ' ' + \
                    '-DCMAKE_BUILD_TYPE=Release'
    os.system('cmake ' + cmake_options + ' ../llvm')

    # Build project
    print("Building Clang:")
    # os.system("make")
    os.system("make install -j2")

    # Return to working directory before leave
    os.chdir(working_dir)

if __name__ == "__main__":
    build()
