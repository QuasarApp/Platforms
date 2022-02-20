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

/**
 * @brief The Purchase struct contains base purchese information.
 */
struct PLATFORMS_EXPORT Purchase {
    /// This is human readable id of purchese
    QString id;
    /// This is token that you should be send to server for validation
    QString token;
    /// Count of purchase
    int count = 0;
};

/**
 * @brief The IBilling class is base interface for make purcheses in diferent platforms.
 */
class PLATFORMS_EXPORT IBilling: public QObject
{
    Q_OBJECT
public:
    IBilling();

    /**
     * @brief instance This method return platform's dependet billing object. If this library not support current platform then return nullptr.
     * @return platform's dependet billing object
     * @note If this library not support current platform then return nullptr.
     */
    static IBilling* instance();

    /**
     * @brief init This method initialize the billing system of platform. This method should be invoked before using billing system.
     */
    virtual void init() = 0;

public slots:
    /**
     * @brief getItem This method try bye item with id @a itemId.
     * @param itemID This is text id of a purchese.
     */
    virtual void getItem(const QString &itemID) = 0;

    /**
     * @brief isSupported This method return true if the current device support billing.
     * @return true if the device support billing else false.
     */
    virtual bool isSupported() = 0;

signals:

    /**
     * @brief sigPurchaseReceived This signal emmited when user bye or subscribe new item.
     */
    void sigPurchaseReceived(Platforms::Purchase);

};

}

Q_DECLARE_METATYPE(Platforms::Purchase)
#endif // IBILLING_H
