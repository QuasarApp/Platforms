//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#ifndef IBILLING_H
#define IBILLING_H

#include <QObject>
#include "Platforms/global.h"

namespace Platforms {

struct PLATFORMS_EXPORT Purchase {
    QString id;
    QString token;
    int count = 0;
};

class PLATFORMS_EXPORT IBilling: public QObject
{
    Q_OBJECT
public:
    IBilling();
    static IBilling* instance();

    virtual void init() = 0;

public slots:
    virtual void getItem(const QString &itemID) = 0;
    virtual bool isSupported() = 0;

signals:
    void sigPurchaseReceived(Platforms::Purchase);

};

}

Q_DECLARE_METATYPE(Platforms::Purchase)
#endif // IBILLING_H
