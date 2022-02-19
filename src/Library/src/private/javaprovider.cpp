//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "javaprovider.h"



#ifdef Q_OS_ANDROID

#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)

#include <QJniEnvironment>
#define JENV QJniEnvironment
#define JOBJ QJniObject

#else

#include <QAndroidJniEnvironment>
#define JENV QAndroidJniEnvironment
#define JOBJ QAndroidJniObject

#endif

JavaProvider *JavaProvider::instance() {
    static JavaProvider* instance = new JavaProvider();
    return instance;
}

void JavaProvider::getBillingItem(const QString &item) const {
    auto javaItem = JOBJ::fromString(item);
    JOBJ::callStaticMethod<void>("com/quasarapp/androidtools/CppProvider",
                                 "setWindowFlags",
                                 "(Ljava/lang/String)V",
                                 javaItem.object<jstring>());
}

JavaProvider::JavaProvider() {

    JNINativeMethod methods[] {
        {"purchaseReceived", "(Ljava/lang/String;Ljava/lang/String;)V", reinterpret_cast<void *>(purchaseReceived)},
    };

    JOBJ javaClass("com/quasarapp/androidtools/CppProvider");
    JENV env;
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
    env->RegisterNatives(objectClass,
                         methods,
                         sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(objectClass);

}

void JavaProvider::initBilling() const {
    JOBJ::callStaticMethod<void>("com/quasarapp/androidtools/CppProvider",
                                 "initBilling",
                                 "()V");
}

void JavaProvider::setWindowFlags(int flag, bool enable) const {
    JOBJ::callStaticMethod<void>("com/quasarapp/androidtools/CppProvider",
                                 "setWindowFlags", "(IZ)V", flag, enable);
}

bool JavaProvider::addPermision(const QString &permisionName) const {
    auto javaItem = JOBJ::fromString(permisionName);
    jboolean result = JOBJ::callStaticMethod<jboolean>("com/quasarapp/androidtools/CppProvider",
                                     "addPermision",
                                     "(Ljava/lang/String)Z",
                                     javaItem.object<jstring>());
    return result;

}

void JavaProvider::purchaseReceived(JNIEnv *env, jobject thiz, jstring id, jstring token) {
    Q_UNUSED(thiz)

    emit JavaProvider::instance()->sigPurchase(env->GetStringUTFChars(id, 0),
                                               env->GetStringUTFChars(token, 0));
}

#endif
