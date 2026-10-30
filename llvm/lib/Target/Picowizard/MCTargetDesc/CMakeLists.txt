add_llvm_component_library(LLVMPicowizardDesc
  PicowizardMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  PicowizardInfo
  Support
  TargetParser

  ADD_TO_COMPONENT
  Picowizard
)

add_dependencies(LLVMPicowizardDesc PicowizardCommonTableGen)

