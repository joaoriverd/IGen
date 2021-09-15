# A Compiler for Sound Floating-Point

A source-to-source compiler that translates a numerical C program performing floating-point
computations to an equivalent sound numerical C program using interval arithmetic.
By sound we mean that the resulting intervals are guaranteed to contain the result of the
original program if it were performed using real arithmetic.

### Dependencies

 * CMake 3.10 (https://cmake.org/)
 * Python 3.6 or higher (https://www.python.org/)
 * LLVM Project 11.0.1 (https://github.com/llvm/llvm-project)
 * MPFR 4.0.1 (http://www.mpfr.org/)
 * CR-LIBM 1.0 (https://github.com/taschini/crlibm)

### Compiling Clang

We provide a source code of Clang 11.0.1 with slight modifications to support custom
language extensions. For the original code see: https://github.com/llvm/llvm-project.git.

To build clang run the following commands:
  * ``cd <igen_path>/third-party/llvm-project-11.0.1``
  * ``python3 build.py``

The compilation may take a while.

### Compiling IGen

To build IGen run the following:
 - `cd scripts`
 - `python3 install_igen.py`

**Note**: Check the appendix below for common errors when building IGen.

### Using IGen

The script `<igen_path>/bin/igen.py` can be used to compile stand-alone
files. For example:

 - `cd <igen_path>/bin`
 - `python igen.py test.c`

This will compile `test.c` and generate `igen_test.c`

### Appendix

#### Installing dependencies in Ubuntu 20.04

 - CMake: ``sudo apt install cmake``
 - MPFR: ``sudo apt install libmpfr-dev``
 - Python: ``sudo apt install python3.8``
 - CR-LIBM:
   - Download from https://github.com/taschini/crlibm
   - ``.\prepare``
   - In case of error ``aclocal: not found`` do:
      - ``sudo apt-get install autotools-dev``
      - ``sudo apt-get install automake``
   - ``sudo make install``

#### Errors when compiling IGen

For Linux (tested on Ubuntu 20.04):

 1. `/usr/bin/ld: cannon find -lz`
    - Solution: `sudo apt-get install zlib1g-dev`
 2. `/usr/bin/ld: cannon find -ltinfo`
     - Solution: `sudo apt-get install libtinfo-dev`
