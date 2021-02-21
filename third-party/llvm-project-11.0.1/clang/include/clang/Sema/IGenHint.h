#ifndef LLVM_CLANG_SEMA_IGENHINT_H
#define LLVM_CLANG_SEMA_IGENHINT_H

#include "clang/Basic/IdentifierTable.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Sema/Ownership.h"

namespace clang {
struct IGenHint {
  SourceRange Range;
  IdentifierLoc *PragmaNameLoc;
  IdentifierLoc *OptionLoc;
  Expr *ValueExpr;

  IGenHint()
      : PragmaNameLoc(nullptr), OptionLoc(nullptr), ValueExpr(nullptr) {}
};

}
#endif // LLVM_CLANG_SEMA_IGENHINT_H
