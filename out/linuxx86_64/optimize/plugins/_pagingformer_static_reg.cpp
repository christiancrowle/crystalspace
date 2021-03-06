/ This file is automatically generated.
#include "cssysdef.h"
#include "csutil/scf.h"

/ Put static linking stuff into own section.
/ The idea is that this allows the section to be swapped out but not
// swapped in again b/c something else in it was needed.
#if !defined(CS_DEBUG) && defined(CS_COMPILER_MSVC)
#pragma const_seg(".CSmetai")
#pragma comment(linker, "/section:.CSmetai,r")
#pragma code_seg(".CSmeta")
#pragma comment(linker, "/section:.CSmeta,er")
#pragma comment(linker, "/merge:.CSmetai=.CSmeta")
#endif

namespace csStaticPluginInit
{
static char const metainfo_pagingformer[] =
"<?xml version=\"1.0\"?>"
"<!-- pagingformer.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.terraformer.paging</name>"
"        <implementation>csPagingFormer</implementation>"
"        <description>Paging terrain formation generator</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csPagingFormer_FACTORY_REGISTER_DEFINED 
  #define csPagingFormer_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csPagingFormer) 
  #endif

class pagingformer
{
SCF_REGISTER_STATIC_LIBRARY(pagingformer,metainfo_pagingformer)
  #ifndef csPagingFormer_FACTORY_REGISTERED 
  #define csPagingFormer_FACTORY_REGISTERED 
    csPagingFormer_StaticInit csPagingFormer_static_init__; 
  #endif
public:
 pagingformer();
};
pagingformer::pagingformer() {}

}
