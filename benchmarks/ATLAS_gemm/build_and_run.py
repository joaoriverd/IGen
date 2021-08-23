import os

def build_and_run():
    tests = ["baseline", "f64i", "ddi"]
    dirname   = os.path.dirname(__file__)
    working_dir = os.getcwd()

    for test in tests:
        build_dir = os.path.join(dirname, "build_" + test)
        os.makedirs(build_dir, exist_ok=True)

        # Running CMake
        print("Generating build infrastructure for " + test)
        os.chdir(build_dir)
        cmd = "cmake -DINTERVAL_COMPILATION=" + test + " " + dirname
        os.system(cmd)

        # Build project
        print("Building GEMM vectorized baseline:")
        os.system("make")

        # Start benchmark
        print("Running GEMM benchmark for " + test)
        os.system("./ATLAS_gemm")

    os.chdir(working_dir)


if __name__ == "__main__":
    build_and_run()