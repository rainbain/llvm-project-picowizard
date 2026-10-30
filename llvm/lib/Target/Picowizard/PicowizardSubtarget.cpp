//===-- PicowizardSubtarget.cpp - Picowizard Subtarget Information ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the Picowizard specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "PicowizardSubtarget.h"

#define DEBUG_TYPE "picowizard-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "PicowizardGenSubtargetInfo.inc"

namespace llvm {

PicowizardSubtarget::PicowizardSubtarget(const Triple &TT, StringRef CPU, StringRef FS)
    : PicowizardGenSubtargetInfo(TT, CPU, /* TuneCPU */ CPU, FS) {

        ParseSubtargetFeatures(CPU, /* TuneCPU */ CPU, FS);
}

} // end namespace llvm