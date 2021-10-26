import os

def build_and_run():
    # Create building directory
    dirname   = os.path.dirname(__file__)
    build_dir_vec = os.path.join(dirname, "build_vec")
    build_dir_ss  = os.path.join(dirname, "build_ss")
    os.makedirs(build_dir_vec, exist_ok=True)
    os.makedirs(build_dir_ss , exist_ok=True)
    working_dir = os.getcwd()

    # Running CMake for IGen-vv and IGen-sv
    print("Generating build infrastructure for IGen-vv and IGen-sv:")
    os.chdir(build_dir_vec)
    os.system("cmake -DIGEN_VEC=YES ..")

    # Build project
    print("Building DFT for IGen-vv and IGen-sv (and interval libs):")
    os.system("make")

    # Start benchmark
    print("Running DFT benchmark for IGen-vv and IGen-sv:")
    os.system("./Spiral_DFT")

    # Running CMake of IGen-ss
    #print("Generating build infrastructure for IGen-ss:")
    #os.chdir(build_dir_ss)
    #os.system("cmake -DIGEN_VEC=NO ..")

    # Build project
    #print("Building DFT for IGen-ss:")
    #os.system("make")

    # Start benchmark
    #print("Running DFT benchmark for IGen-ss:")
    #os.system("./Spiral_DFT")

    os.chdir(working_dir)


if __name__ == "__main__":
    build_and_run()
