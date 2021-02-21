#include <iostream>
#include "commonInterval.h"
#include "ASTVisitor.h"
#include "pollyReduction.h"


using namespace std;

bool parseIgenConfigArguments (const char** igen_args, int igen_argc) {
    bool err = false;
    string lib  = igen_args[igen_argc - 3]; // Library argument
    string mode = igen_args[igen_argc - 2]; // Transformation mode argument.
    string red  = igen_args[igen_argc - 1]; // CSV file with polly reductions

    GlobalPollyReduction.setRedCSVFileName(red);

    if (lib == "-lib=igen") {
        setIntervalLib(IAGEN);
    }
    else if (lib == "-lib=mpfi") {
        setIntervalLib(MPFI_LIB);
    }
    else if (lib == "-lib=boost") {
        setIntervalLib(BOOST_LIB);
    }
    else if (lib == "-lib=filib") {
        setIntervalLib(FILIB_LIB);
    }
    else {
        cerr << "Library not supported" << endl;
        err = true;
    }

    if (mode == "-tmode=normal") {
        setTransformationMode(NORMAL_MODE);
    }
    else if (mode == "-tmode=promote_float") {
        setTransformationMode(PROMOTE_TO_FP32_MODE);
    }
    else if (mode == "-tmode=promote_double") {
        setTransformationMode(PROMOTE_TO_FP64_MODE);
    }
    else if (mode == "-tmode=promote_dd") {
        setTransformationMode(PROMOTE_TO_DD_MODE);
    }
    else {
        cerr << "Transformation mode not supported. Using default." << endl;
    }

    return err;
}

int main(int argc, const char **argv) {

    /* Last two argument are always library argument and transformation mode */
    bool err = parseIgenConfigArguments(argv, argc);
    if (err) {
        return 1;
    }

    /* parse the command-line args passed to your code */
    const char** libToolingArgv = argv;
    int libToolingArgc = argc - 3;  // The last two arguments are already processed
    int status = runIntervalGenTool(libToolingArgc, libToolingArgv);

    return status;
}
