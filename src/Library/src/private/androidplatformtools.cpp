//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#include "androidplatformtools.h"
#include <QCoreApplication>

#ifdef Q_OS_ANDROID

#include "javaprovider.h"

#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
#include <QJniEnvironment>
#include <QJniObject>
#include <QJniEnvironment>
#define JENV QJniEnvironment
#define JOBJ QJniObject

#else
#include <QAndroidJniEnvironment>
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>

#define JENV QAndroidJniEnvironment
#define JOBJ QAndroidJniObject

#endif
#include <QObject>

namespace Platforms {

AndroidPlatformTools::AndroidPlatformTools() {
    _javaProvider = JavaProvider::instance();
}

void AndroidPlatformTools::setScreanDim(bool enable) const {
    const int FLAG_KEEP_SCREEN_ON = 128;
    _javaProvider->setWindowFlags(FLAG_KEEP_SCREEN_ON, enable);
}

bool AndroidPlatformTools::getAccessToWriteInStorage() {

    return _javaProvider->addPermision("android.permission.WRITE_EXTERNAL_STORAGE");
}

bool AndroidPlatformTools::getAccessToReadInStorage() {
    return _javaProvider->addPermision("android.permission.READ_EXTERNAL_STORAGE");

}

}
#endif
