#pragma once
#include <QtCore/QtGlobal>

#ifdef BUILD_DYNAMIC
#    if defined(Export_Library)
#        define DLL_API Q_DECL_EXPORT
#    else
#        define DLL_API Q_DECL_IMPORT
#    endif
#else
#    define DLL_API
#endif
