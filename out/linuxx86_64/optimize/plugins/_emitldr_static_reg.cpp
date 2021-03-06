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
static char const metainfo_emitldr[] =
"<?xml version=\"1.0\"?>"
"<!-- emitldr.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.mesh.loader.emit</name>"
"        <implementation>csEmitLoader</implementation>"
"        <description>Crystal Space Emit Mesh Loader</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.loader.factory.emit</name>"
"        <implementation>csEmitFactoryLoader</implementation>"
"        <description>Crystal Space Emit Factory Loader</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.saver.emit</name>"
"        <implementation>csEmitSaver</implementation>"
"        <description>Crystal Space Emit Mesh Saver</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.saver.factory.emit</name>"
"        <implementation>csEmitFactorySaver</implementation>"
"        <description>Crystal Space Emit Factory Saver</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csEmitLoader_FACTORY_REGISTER_DEFINED 
  #define csEmitLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csEmitLoader) 
  #endif
  #ifndef csEmitFactoryLoader_FACTORY_REGISTER_DEFINED 
  #define csEmitFactoryLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csEmitFactoryLoader) 
  #endif
  #ifndef csEmitSaver_FACTORY_REGISTER_DEFINED 
  #define csEmitSaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csEmitSaver) 
  #endif
  #ifndef csEmitFactorySaver_FACTORY_REGISTER_DEFINED 
  #define csEmitFactorySaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csEmitFactorySaver) 
  #endif

class emitldr
{
SCF_REGISTER_STATIC_LIBRARY(emitldr,metainfo_emitldr)
  #ifndef csEmitLoader_FACTORY_REGISTERED 
  #define csEmitLoader_FACTORY_REGISTERED 
    csEmitLoader_StaticInit csEmitLoader_static_init__; 
  #endif
  #ifndef csEmitFactoryLoader_FACTORY_REGISTERED 
  #define csEmitFactoryLoader_FACTORY_REGISTERED 
    csEmitFactoryLoader_StaticInit csEmitFactoryLoader_static_init__; 
  #endif
  #ifndef csEmitSaver_FACTORY_REGISTERED 
  #define csEmitSaver_FACTORY_REGISTERED 
    csEmitSaver_StaticInit csEmitSaver_static_init__; 
  #endif
  #ifndef csEmitFactorySaver_FACTORY_REGISTERED 
  #define csEmitFactorySaver_FACTORY_REGISTERED 
    csEmitFactorySaver_StaticInit csEmitFactorySaver_static_init__; 
  #endif
public:
 emitldr();
};
emitldr::emitldr() {}

}
