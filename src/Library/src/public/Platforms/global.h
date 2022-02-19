//#
//# Copyright (C) 2018-2022 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef PLATFORMS_GLOBAL_H
#define PLATFORMS_GLOBAL_H

#include <QtCore/qglobal.h>

#define PLATFORMS_VERSION "0.1.29d91f8"

#if defined(PLATFORMS_LIBRARY)
#  define PLATFORMS_EXPORT Q_DECL_EXPORT
#else
#  define PLATFORMS_EXPORT Q_DECL_IMPORT
#endif

#endif //PLATFORMS_GLOBAL_H
