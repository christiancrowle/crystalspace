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
static char const metainfo_joylin[] =
"<?xml version=\"1.0\"?>"
"<!-- joylin.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.device.joystick.linux</name>"
"        <implementation>csLinuxJoystick</implementation>"
"        <description>Crystal Space Joystick plugin for GNU/Linux</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.device.joystick</name>"
"        <implementation>csLinuxJoystick</implementation>"
"        <description>Crystal Space Joystick plugin for GNU/Linux</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csLinuxJoystick_FACTORY_REGISTER_DEFINED 
  #define csLinuxJoystick_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csLinuxJoystick) 
  #endif
  #ifndef csLinuxJoystick_FACTORY_REGISTER_DEFINED 
  #define csLinuxJoystick_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csLinuxJoystick) 
  #endif

class joylin
{
SCF_REGISTER_STATIC_LIBRARY(joylin,metainfo_joylin)
  #ifndef csLinuxJoystick_FACTORY_REGISTERED 
  #define csLinuxJoystick_FACTORY_REGISTERED 
    csLinuxJoystick_StaticInit csLinuxJoystick_static_init__; 
  #endif
  #ifndef csLinuxJoystick_FACTORY_REGISTERED 
  #define csLinuxJoystick_FACTORY_REGISTERED 
    csLinuxJoystick_StaticInit csLinuxJoystick_static_init__; 
  #endif
public:
 joylin();
};
joylin::joylin() {}

}
