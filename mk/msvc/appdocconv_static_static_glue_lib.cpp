// This file is automatically generated.
#include "cssysdef.h"

#if defined(CS_GLUE_IS_SHARED)
  CS_DECLARE_DEFAULT_STATIC_VARIABLE_REGISTRATION
  // Needed to work around some order of initialization issues
  static void csStaticVarCleanup_local (void (*p)())
  { csStaticVarCleanup_csutil (p); }
  CS_DEFINE_STATIC_VARIABLE_REGISTRATION (csStaticVarCleanup_local);
  #define BIND_EXPORT CS_EXPORT_SYM
#else
  #define BIND_EXPORT
#endif
struct BIND_EXPORT _Bind_docconv_static_plugins
{
  _Bind_docconv_static_plugins ();
};
struct _static_use { _static_use (); };
_Bind_docconv_static_plugins::_Bind_docconv_static_plugins () {}
// Needed to pull in _cs_static_use object file
namespace { _static_use _static_use_bind; }

