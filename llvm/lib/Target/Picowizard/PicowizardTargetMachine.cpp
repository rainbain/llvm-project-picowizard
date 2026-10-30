//===-- PicowizardTargetMachine.cpp - Define TargetMachine for Picowizard -------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the Picowizard specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#include "PicowizardTargetMachine.h"
#include "TargetInfo/PicowizardTargetInfo.h"

#include "llvm/MC/TargetRegistry.h"

namespace llvm {

/// Processes a CPU name.
static StringRef getCPU(StringRef CPU) {
    if(CPU.empty() || CPU == "generic") {
        return "pw120";
    }

    return CPU;
}

// Default to staticly relocated code, report unsupported
static Reloc::Model getEffectiveRelocModel(std::optional<Reloc::Model> RM) {
    if(RM) {
        if(*RM == Reloc::Model::PIC_)
            reportFatalUsageError("Target does not support the PIC relocation model");
        if(*RM == Reloc::Model::DynamicNoPIC)
            reportFatalUsageError("Target does not support the dynamic no PIC relocation model");
        if(*RM == Reloc::Model::ROPI)
            reportFatalUsageError("Target does not support the ROPI relocation model");
        if(*RM == Reloc::Model::RWPI)
            reportFatalUsageError("Target does not support the RWPI relocation model");
        if(*RM == Reloc::Model::ROPI_RWPI)
            reportFatalUsageError("Target does not support the ROPI RWPI relocation model");
        
        return *RM;
    }

    return Reloc::Model::Static;
}

// Default to small, report unsupported
static CodeModel::Model getEffectiveCodeModel(std::optional<CodeModel::Model> CM) {
    if(CM) {
        if(*CM == CodeModel::Tiny)
            reportFatalUsageError("Target does not support the tiny CodeModel");
        if(*CM == CodeModel::Kernel)
            reportFatalUsageError("Target does not support the kernel CodeModel");
        if(*CM == CodeModel::Medium)
            reportFatalUsageError("Target does not support the medium CodeModel");
        if(*CM == CodeModel::Large)
            reportFatalUsageError("Target does not support the large CodeModel");

        return *CM;
    }

    return CodeModel::Small;
}

PicowizardTargetMachine::PicowizardTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL,
                                   bool JIT)
    : CodeGenTargetMachineImpl(T, TT, getCPU(CPU), FS, Options,
                               getEffectiveRelocModel(RM),
                               getEffectiveCodeModel(CM), OL),
    SubTarget(TT, CPU, FS) {
    // meow
}

const PicowizardSubtarget *PicowizardTargetMachine::getSubtargetImpl(const Function &) const {
  return &SubTarget;
}


TargetPassConfig *createPassConfig(PassManagerBase &PM) {
    // meow
    return NULL; // I am null meow
}

MachineFunctionInfo *
createMachineFunctionInfo(BumpPtrAllocator &Allocator, const Function &F,
                          const TargetSubtargetInfo *STI) {
    return NULL; // I am null meow
}

// Called by LLVMs internals to register and initialize the target
extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void LLVMInitializePicowizardTarget() {
  // Register the target.
  RegisterTargetMachine<PicowizardTargetMachine> X(getThePicowizardTarget());
}

} // end namespace llvm
