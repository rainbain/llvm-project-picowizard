add_llvm_component_group(Picowizard)

set(LLVM_TARGET_DEFINITIONS Picowizard.td)

#tablegen(LLVM AVRGenAsmMatcher.inc -gen-asm-matcher)
#tablegen(LLVM AVRGenAsmWriter.inc -gen-asm-writer)
#tablegen(LLVM AVRGenCallingConv.inc -gen-callingconv)
#tablegen(LLVM AVRGenDAGISel.inc -gen-dag-isel)
#tablegen(LLVM AVRGenDisassemblerTables.inc -gen-disassembler)
#tablegen(LLVM AVRGenInstrInfo.inc -gen-instr-info)
#tablegen(LLVM AVRGenMCCodeEmitter.inc -gen-emitter)
#tablegen(LLVM AVRGenRegisterInfo.inc -gen-register-info)
#tablegen(LLVM AVRGenSDNodeInfo.inc -gen-sd-node-info)
tablegen(LLVM PicowizardGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(PicowizardCommonTableGen)

add_llvm_target(PicowizardCodeGen
  PicowizardTargetMachine.cpp
  PicowizardSubtarget.cpp

#  DEPENDS
#  intrinsics_gen

  LINK_COMPONENTS
  CodeGen
  Core
  MC
  PicowizardDesc
  PicowizardInfo
  Support
  Target
  TargetParser

  ADD_TO_COMPONENT
  Picowizard
)

#add_subdirectory(AsmParser)
#add_subdirectory(Disassembler)
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
