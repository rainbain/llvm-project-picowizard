//===-- Picowizard.td - Describe the Picowizard Target Machine ----------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===---------------------------------------------------------------------===//
// This is the top level entry point for the Picowizard target.
//===---------------------------------------------------------------------===//

//===---------------------------------------------------------------------===//
// Target-independent interfaces which we are implementing
//===---------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===---------------------------------------------------------------------===//
// Picowizard Device Definitions
//===---------------------------------------------------------------------===//

include "PicowizardDevices.td"

//===---------------------------------------------------------------------===//
// Target Declaration
//===---------------------------------------------------------------------===//

def Picowizard : Target {
    
}