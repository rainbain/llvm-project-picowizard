//===-- PicowizardTargetInfo.cpp - Picowizard Target Implementation ---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "TargetInfo/PicowizardTargetInfo.h"

#include "llvm/MC/TargetRegistry.h"

namespace llvm {

Target &getThePicowizardTarget() {
    static Target ThePicowizardTarget;
    return ThePicowizardTarget;
}

} // end namespace llvm


extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializePicowizardTargetInfo() {
    llvm::RegisterTarget<llvm::Triple::picowizard> X(llvm::getThePicowizardTarget(), "picowizard", "RascalFoxfire Picowizard RISC Architecture", "Picowizard");
}
