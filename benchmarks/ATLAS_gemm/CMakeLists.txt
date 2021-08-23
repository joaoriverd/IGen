# ================================================================================
# Add here user defined variables
# ================================================================================
if (NOT DEFINED INTERVAL_COMPILATION)
    set(INTERVAL_COMPILATION "ddi") # ddi, f64i or baseline.
endif()

set(ATLAS_SOURCE  atlas_include/ATLAS)
set(ATLAS_INCLUDE atlas_include/include)
set(IGEN_LIB      ../../igen_lib)
set(IGEN_COMMON   ../../common)

# ================================================================================
# User configuration. E.g. compiler, debug, verbose, etc
# ================================================================================
set(PROJECT_NAME ATLAS_gemm)         # Specify project name
set(CONFIG_COMPILER "GNU")           # GNU, Clang or Intel
set(CONFIG_DEBUG "OFF")              # ON or OFF
set(CONFIG_GENERATE_ASSEMBLY "OFF")  # ON or OFF
set(CMAKE_VERBOSE_MAKEFILE "OFF")    # ON or OFF
set(CONFIG_FLAGS "-O3 -march=native -frounding-math")
set(CONFIG_LIBRARIES crlibm mpfr) # Used libraries, e.g. crlibm, mpfr

# ================================================================================
# Include directories, set source files and user definitions
# ================================================================================
add_definitions(
        -DIGEN_LIB_VECTORIZED

        # ATLAS necessary defines (extracted from compilation process)
        -DL2SIZE=33554432
        -DAdd_
        -DF77_INTEGER=int
        -DStringSunStyle
        -DATL_OS_Linux
        -DATL_ARCH_Corei4
        -DATL_CPUMHZ=2289
        -DATL_AVXMAC
        -DATL_AVX
        -DATL_SSE3
        -DATL_SSE2
        -DATL_SSE1
        -DATL_USE64BITS
        -DATL_GAS_x8664
        -DATL_NCPU=12
        -DDREAL
        -DNoTransA_
        -DNoTransB_
        -DALPHAX
        -DBETAX
        -DATL_UCLEANM
        -DATL_UCLEANN
        -DATL_UCLEANK
 )

if (${INTERVAL_COMPILATION} STREQUAL f64i)
    add_definitions(-DF64I_TEST)
    include_directories(atlas_f64i)
elseif(${INTERVAL_COMPILATION} STREQUAL ddi)
    add_definitions(-DDDI_TEST)
    include_directories(atlas_ddi)
endif()

include_directories(
        ${ATLAS_SOURCE}/include
        ${ATLAS_INCLUDE}/atlas
        ${IGEN_LIB}
        ${IGEN_COMMON}
)

AUX_SOURCE_DIRECTORY(atlas_f64i IGEN_F64_SRC)
AUX_SOURCE_DIRECTORY(atlas_ddi IGEN_DD_SRC)
AUX_SOURCE_DIRECTORY(atlas_source ATLAS_SRC)

if (${INTERVAL_COMPILATION} STREQUAL f64i)
    set(SOURCE_FILES
            ${IGEN_F64_SRC}
            dgemm_simple_f64i.cpp
            dgemm_bench_f64i.cpp
            )
elseif(${INTERVAL_COMPILATION} STREQUAL ddi)
    set(SOURCE_FILES
            ${IGEN_DD_SRC}
            dgemm_simple_ddi.cpp
            dgemm_bench_ddi.cpp
            )
else()
    set(SOURCE_FILES
            ${ATLAS_SRC}
            dgemm_bench_scalar.cpp
            dgemm_simple.cpp
            )
endif()

set(SOURCE_FILES ${SOURCE_FILES}
        benchmark/tsc_x86.cpp
        main.cpp

        # Auxilary files
        ${IGEN_COMMON}/util.cpp
        ${IGEN_LIB}/igen_dd_immintrin_fallback.c
        ${IGEN_LIB}/igen_immintrin_fallback.c
        )

# ================================================================================
# Do not modify the following
# ================================================================================
cmake_minimum_required(VERSION 3.14)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

# ================================================================================
# Specify compiler and flags (do not change this)
# ================================================================================
if (${CONFIG_COMPILER} STREQUAL GNU)
    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")
    set(CMAKE_C_COMPILER_ID "GNU")
    set(CMAKE_CXX_COMPILER_ID "GNU")
elseif(${CONFIG_COMPILER} STREQUAL Clang)
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_C_COMPILER_ID "Clang")
    set(CMAKE_CXX_COMPILER_ID "Clang")
elseif(${CONFIG_COMPILER} STREQUAL Intel)
    set(CMAKE_C_COMPILER "/opt/intel/bin/icc")
    set(CMAKE_CXX_COMPILER "/opt/intel/bin/icpc")
    set(CMAKE_C_COMPILER_ID "Intel")
    set(CMAKE_CXX_COMPILER_ID "Intel")
else()
    message([FATAL_ERROR] " Compiler not selected correctly in CMakeLists. Using default config" ...)
endif ()

# Reset compiler flags to get full control
set(CMAKE_C_FLAGS           "")
set(CMAKE_CXX_FLAGS         "")
set(CMAKE_C_FLAGS_RELEASE   "")
set(CMAKE_CXX_FLAGS_RELEASE "")
set(CMAKE_C_FLAGS_DEBUG     "")
set(CMAKE_CXX_FLAGS_DEBUG   "")

# Define standard
set(CMAKE_C_FLAGS   "-std=c11")
set(CMAKE_CXX_FLAGS "-std=c++11")

if (${CONFIG_DEBUG} STREQUAL "ON")
    # Debug flag
    set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -O0 -g -march=native --coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -march=native --coverage")
else()
    # Set compiler flags
    set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS} ${CONFIG_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CONFIG_FLAGS}")
endif ()


# ================================================================================
# Define binary executable and libraries to be linked (Do not change this)
# ================================================================================
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if (${CONFIG_GENERATE_ASSEMBLY} MATCHES "ON")
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS -save-temps)
endif ()

# Add math library for floating point environment
target_link_libraries(${PROJECT_NAME} ${CONFIG_LIBRARIES})
