//
// Copyright (C) 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef IPLATFORMTOOLS_H
#define IPLATFORMTOOLS_H

#include <QtGlobal>
#include "Platforms/global.h"

namespace Platforms {

/**
 * @class IPlatformTools
 * @brief Base interface for platform-specific utility functions
 * 
 * This interface provides access to platform-dependent system utilities
 * such as screen dimming, storage access, and other OS-specific features.
 * Each platform has its own implementation that handles the appropriate
 * system calls and permissions.
 * 
 * @note This interface uses a singleton pattern via instance() method.
 * @note Implementations are platform-specific and may return nullptr if
 *       the feature is not available on the current platform.
 * 
 * @since 3.0.0
 */
class PLATFORMS_EXPORT IPlatformTools
{
public:
    /**
     * @brief Virtual destructor
     * 
     * Provides a virtual destructor for proper cleanup of derived classes.
     */
    virtual ~IPlatformTools() = default;

    /**
     * @brief Get the platform tools instance
     * 
     * Returns a pointer to the platform-specific tools instance.
     * Uses singleton pattern to ensure a single instance per platform.
     * 
     * @return Pointer to IPlatformTools instance, or nullptr if unsupported
     * 
     * @note This method is thread-safe
     * @note The instance is lazily initialized on first call
     */
    static IPlatformTools* instance();

    /**
     * @brief Set screen dim mode
     * 
     * Enables or disables screen dimming on the device.
     * Platform-specific implementation handles the appropriate system call.
     * 
     * @param enable true to enable screen dim, false to disable
     * 
     * @note This is a pure virtual method - must be implemented by derived classes
     * @note Behavior may vary by platform
     */
    virtual void setScreanDim(bool enable) const = 0;

    /**
     * @brief Request write access to external storage
     * 
     * Attempts to obtain permission for writing to external storage.
     * Platform-specific implementations handle the appropriate permission dialog.
     * 
     * @return true if access granted, false otherwise
     * 
     * @note This is a pure virtual method - must be implemented by derived classes
     * @note On Android, this typically triggers a permission dialog
     */
    virtual bool getAccessToWriteInStorage() = 0;

    /**
     * @brief Request read access to external storage
     * 
     * Attempts to obtain permission for reading from external storage.
     * Platform-specific implementations handle the appropriate permission dialog.
     * 
     * @return true if access granted, false otherwise
     * 
     * @note This is a pure virtual method - must be implemented by derived classes
     * @note On Android, this typically triggers a permission dialog
     */
    virtual bool getAccessToReadInStorage() = 0;

protected:
    /**
     * @brief Protected default constructor
     * 
     * Default constructor for use by derived classes.
     */
    IPlatformTools() = default;

};
}

#endif // IPLATFORMTOOLS_H
