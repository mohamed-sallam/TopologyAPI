#ifndef TOPOLOGYAPI_GLOBAL_H
#define TOPOLOGYAPI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TOPOLOGYAPI_LIBRARY)
#  define TOPOLOGYAPI_EXPORT Q_DECL_EXPORT
#else
#  define TOPOLOGYAPI_EXPORT Q_DECL_IMPORT
#endif

#endif // TOPOLOGYAPI_GLOBAL_H
