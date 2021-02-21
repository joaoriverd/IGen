cmake_minimum_required(VERSION 3.13)
project(igen)
set(CMAKE_CXX_STANDARD 14)

set(CLANG_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/../third-party/llvm-project-11.0.1/install/lib)
set(CLANG_BIN_PATH     ${PROJECT_SOURCE_DIR}/../third-party/llvm-project-11.0.1/install/bin)
set(CLANG_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/../third-party/llvm-project-11.0.1/install/include)

# ================================================================================
# Reset the C/C++ flags, and take full control
# ================================================================================
set(CMAKE_C_FLAGS           "-g")
set(CMAKE_CXX_FLAGS         "-g")
set(CMAKE_C_FLAGS_RELEASE   "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-g")
set(CMAKE_C_FLAGS_DEBUG     "-g")
set(CMAKE_CXX_FLAGS_DEBUG   "-g")
#set(CMAKE_VERBOSE_MAKEFILE "ON")

set(CMAKE_C_COMPILER      ${CLANG_BIN_PATH}/clang)
set(CMAKE_CXX_COMPILER    ${CLANG_BIN_PATH}/clang++)
set(CMAKE_C_COMPILER_ID    "Clang")
set(CMAKE_CXX_COMPILER_ID  "Clang")

# ================================================================================
# Include directories and set source files
# ================================================================================
include_directories(
        extra
        utils
        interval
        frontend
        ASTVisitor
        ${CLANG_INCLUDE_PATH}
)

set(SOURCE_FILES
        # Project source files
        main.cpp
        ASTVisitor/ASTVisitor.cpp
        utils/util.cpp
        interval/intervalExpression.cpp
        interval/tempVariables.cpp
        frontend/genVarDecl.cpp
        frontend/genReturnStmt.cpp
        interval/bopExpressions.cpp
        interval/unaryOpExpressions.cpp
        interval/bopExpressionsMPFI.cpp
        interval/unaryOpExpressionsMPFI.cpp
        interval/constantExpressions.cpp
        interval/commonInterval.cpp
        interval/intrinsicExpression.cpp
        interval/intrinsicExpression.h
        interval/supportedIntrinsics.cpp
        interval/ifStmtParser.cpp
        interval/forStmtParser.cpp
        interval/igenPragmaParser.cpp
#        ASTVisitor/ASTTraverser.cpp
        interval/ASTAnalyzer.cpp
        extra/pollyReduction.cpp
        )

# ================================================================================
# C++ Global Flags
# ================================================================================
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # clang - C++ flags
    set(CMAKE_CXX_FLAGS "-fPIC -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wmissing-field-initializers -pedantic -Wimplicit-fallthrough -Wcovered-switch-default -Wno-noexcept-type -Wnon-virtual-dtor -Wdelete-non-virtual-dtor -Wno-comment -Wstring-conversion -fdiagnostics-color -fno-common -Woverloaded-virtual -Wno-nested-anon-types -fno-rtti" #-fno-exceptions
     )
endif()

# ================================================================================
# Define binary executable and libraries to be linked
# ================================================================================
add_executable(igen ${SOURCE_FILES})

target_link_libraries(igen
        ${CLANG_LIBRARY_PATH}/libLLVMSupport.a -lpthread
        ${CLANG_LIBRARY_PATH}/libclangTooling.a
        ${CLANG_LIBRARY_PATH}/libclangRewriteFrontend.a
        ${CLANG_LIBRARY_PATH}/libclangFormat.a
        ${CLANG_LIBRARY_PATH}/libclangToolingInclusions.a
        ${CLANG_LIBRARY_PATH}/libclangToolingCore.a
        ${CLANG_LIBRARY_PATH}/libclangFrontend.a
        ${CLANG_LIBRARY_PATH}/libclangDriver.a
        ${CLANG_LIBRARY_PATH}/libLLVMFrontendOpenMP.a
        ${CLANG_LIBRARY_PATH}/libclangParse.a
        ${CLANG_LIBRARY_PATH}/libLLVMMCParser.a
        ${CLANG_LIBRARY_PATH}/libLLVMOption.a
        ${CLANG_LIBRARY_PATH}/libLLVMProfileData.a
        ${CLANG_LIBRARY_PATH}/libLLVMBitstreamReader.a
        ${CLANG_LIBRARY_PATH}/libclangSerialization.a
        ${CLANG_LIBRARY_PATH}/libclangSema.a
        ${CLANG_LIBRARY_PATH}/libclangAnalysis.a
        ${CLANG_LIBRARY_PATH}/libclangASTMatchers.a
        ${CLANG_LIBRARY_PATH}/libLLVMBitReader.a
        ${CLANG_LIBRARY_PATH}/libclangEdit.a
        ${CLANG_LIBRARY_PATH}/libclangAST.a
        ${CLANG_LIBRARY_PATH}/libclangRewrite.a
        ${CLANG_LIBRARY_PATH}/libclangLex.a
        ${CLANG_LIBRARY_PATH}/libclangBasic.a
        ${CLANG_LIBRARY_PATH}/libLLVMMC.a
        ${CLANG_LIBRARY_PATH}/libLLVMDebugInfoCodeView.a
        ${CLANG_LIBRARY_PATH}/libLLVMDebugInfoMSF.a
        ${CLANG_LIBRARY_PATH}/libLLVMRemarks.a
        ${CLANG_LIBRARY_PATH}/libLLVMCore.a
        ${CLANG_LIBRARY_PATH}/libLLVMBinaryFormat.a
        ${CLANG_LIBRARY_PATH}/libLLVMSupport.a -lrt -ldl -lpthread -lm
        ${CLANG_LIBRARY_PATH}/libLLVMDemangle.a
        mpfr
)