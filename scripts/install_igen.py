import os
import shutil

dirname   = os.path.dirname(__file__)
build_dir = os.path.join(dirname, "../src/build")
bin_dir   = os.path.join(dirname, "../bin")

def clean_and_build():
    # Create building directory
    os.makedirs(build_dir, exist_ok=True)
    working_dir = os.getcwd()
    os.chdir(build_dir)

    # Running CMake for IGen-vv and IGen-sv
    print("Generating build infrastructure for IGen:")
    os.system("cmake ..")

    # Build project
    print("Building IGen:")
    os.system("make clean")
    os.system("make")

    os.chdir(working_dir)

def move_bin():
    # Move igen binary to bin folder
    shutil.copy(build_dir + "/igen", bin_dir + "/igen")
    print("Binary moved to bin folder.")

if __name__ == "__main__":
    clean_and_build()
    move_bin()
