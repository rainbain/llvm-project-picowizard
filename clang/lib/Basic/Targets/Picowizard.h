//===--- Picowizard.h - Declare Picowizard target feature support -------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares Picowizard TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_PICOWIZARD_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_PICOWIZARD_H

#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/Support/Compiler.h"
#include "llvm/TargetParser/Triple.h"

namespace clang {
namespace targets {

class LLVM_LIBRARY_VISIBILITY PicowizardTargetInfo : public TargetInfo {
public:
    PicowizardTargetInfo(const llvm::Triple &Triple, const TargetOptions &)
      : TargetInfo(Triple) {
        TLSSupported = false;
        PointerWidth = 16;
        PointerAlign = 8;
        ShortWidth = 16;
        ShortAlign = 8;
        IntWidth = 16;
        IntAlign = 8;
        LongWidth = 32;
        LongAlign = 8;
        LongLongWidth = 64;
        LongLongAlign = 8;
        SuitableAlign = 8;
        DefaultAlignForAttributeAligned = 8;
        HalfWidth = 16;
        HalfAlign = 8;
        FloatWidth = 32;
        FloatAlign = 8;
        DoubleWidth = 32;
        DoubleAlign = 8;
        DoubleFormat = &llvm::APFloat::IEEEsingle();
        LongDoubleWidth = 32;
        LongDoubleAlign = 8;
        LongDoubleFormat = &llvm::APFloat::IEEEsingle();
        SizeType = UnsignedInt;
        PtrDiffType = SignedInt;
        IntPtrType = SignedInt;
        Char16Type = UnsignedInt;
        WIntType = SignedInt;
        Int16Type = SignedInt;
        Char32Type = UnsignedLong;
        SigAtomicType = SignedChar;
        resetDataLayout();
    }

    void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;

    llvm::SmallVector<Builtin::InfosShard> getTargetBuiltins() const override;

    BuiltinVaListKind getBuiltinVaListKind() const override {
        return TargetInfo::VoidPtrBuiltinVaList;
    }

    std::string_view getClobbers() const override { return ""; }

    ArrayRef<const char *> getGCCRegNames() const override {
        static const char *const GCCRegNames[] = { "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7"};
        return llvm::ArrayRef(GCCRegNames);
    }

    ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override {
        return {};
    }

    bool validateAsmConstraint(const char *&Name,
                             TargetInfo::ConstraintInfo &Info) const override {
        return false; // no target-specific constraint letters yet
    }
};

} // end namespace targets
} // end namespace clang

#endif LLVM_CLANG_LIB_BASIC_TARGETS_PICOWIZARD_H