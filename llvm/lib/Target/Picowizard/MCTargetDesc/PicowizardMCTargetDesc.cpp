//===-- PicowizardMCTargetDesc.cpp - Picowizard Target Descriptions ---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides Picowizard specific target descriptions.
//
//===----------------------------------------------------------------------===//


#include "PicowizardMCTargetDesc.h"
#include "TargetInfo/PicowizardTargetInfo.h"

#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

#define GET_SUBTARGETINFO_MC_DESC
#include "PicowizardGenSubtargetInfo.inc"

using namespace llvm;

static MCSubtargetInfo *createPicowizardMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  return createPicowizardMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void LLVMInitializePicowizardTargetMC() {
    // Register the MC subtarget info.
    TargetRegistry::RegisterMCSubtargetInfo(getThePicowizardTarget(),
                                            createPicowizardMCSubtargetInfo);
}