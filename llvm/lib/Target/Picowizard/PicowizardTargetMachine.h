//===-- PicowizardTargetMachine.h - Define TargetMachine for Picowizard -------*- C++ -*-===//
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

#ifndef LLVM_PICOWIZARD_TARGET_MACHINE_H
#define LLVM_PICOWIZARD_TARGET_MACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"

#include "PicowizardSubtarget.h"

namespace llvm {


// A generic picowizard implementation.
class PicowizardTargetMachine : public CodeGenTargetMachineImpl {
public:
    PicowizardTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);
    
    const PicowizardSubtarget *getSubtargetImpl(const Function &) const override;

    TargetLoweringObjectFile *getObjFileLowering() const override {
        return NULL;
    }

    TargetPassConfig *createPassConfig(PassManagerBase &PM) override;

    MachineFunctionInfo *
    createMachineFunctionInfo(BumpPtrAllocator &Allocator, const Function &F,
                            const TargetSubtargetInfo *STI) const override;
    
    bool isNoopAddrSpaceCast(const DataLayout &DL, unsigned SrcAs,
                           unsigned DestAs) const override {
        return true;
    }

    void registerPassBuilderCallbacks(PassBuilder &PB) override;

    Error buildCodeGenPipeline(ModulePassManager &MPM, ModuleAnalysisManager &MAM,
                             raw_pwrite_stream &Out, raw_pwrite_stream *DwoOut,
                             CodeGenFileType FileType,
                             const CGPassBuilderOption &Opt, MCContext &Ctx,
                             PassInstrumentationCallbacks *PIC) override;

    private:
        PicowizardSubtarget SubTarget;
};

} // end namespace llvm

#endif // LLVM_PICOWIZARD_TARGET_MACHINE_H