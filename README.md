# Platforms

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Version](https://img.shields.io/badge/version-3.0.0-blue.svg)](./)
[![QuasarApp](https://img.shields.io/badge/QuasarApp-Platform-yellow.svg)](https://github.com/QuasarApp)

This library contains platform-dependent code for cross-platform development. It provides a unified interface for working with different operating systems and platforms.

## Features

- **Cross-Platform Support**: Works with Android, iOS, macOS, Linux, and Windows
- **Billing Interface**: Unified interface for in-app purchases across platforms
- **Platform Tools**: Platform-specific utilities for system operations
- **Modular Design**: Easy to extend and integrate with other QuasarApp libraries

## Supported Platforms

- **Android** - Full support with billing integration
- **iOS** - Full support with billing integration
- **macOS** - Full support for desktop applications
- **Linux** - Desktop platform support
- **Windows** - Desktop platform support

## Architecture

The library follows the interface-implementation pattern:

### Interfaces

- **`IBilling`** - Base interface for in-app purchases
  - `getItem(itemID)` - Request purchase of an item
  - `isSupported()` - Check if billing is available on current platform
  - `init()` - Initialize the billing system
  - `sigPurchaseReceived()` - Signal emitted when purchase is completed

- **`IPlatformTools`** - Base interface for platform-specific utilities
  - `setScreenDim(enable)` - Enable/disable screen dimming
  - `getAccessToWriteInStorage()` - Request write access to external storage
  - `getAccessToReadInStorage()` - Request read access to external storage

### Implementation Classes

- **`AndroidPlatformTools`** - Android-specific implementation
- **`IOSPlatformTools`** - iOS-specific implementation
- **`OSXPlatformTools`** - macOS-specific implementation
- **`LinuxDesktopPlatfomTools`** - Linux desktop implementation
- **`WindowsDesktopPlatformTool`** - Windows desktop implementation

## Usage

### Initialization

```cpp
#include "qaplatforms.h"

// Initialize the platforms library
Platforms::init();

// Get version
QString version = Platforms::version();
```

### Using Billing

```cpp
#include "qaplatforms.h"
#include <QObject>

class MyBilling : public Platforms::IBilling {
    Q_OBJECT
    
public:
    void init() override {
        // Platform-specific initialization
    }
    
    void getItem(const QString &itemID) override {
        // Request item purchase
    }
    
    bool isSupported() override {
        return true;
    }
};

// Get billing instance
auto billing = Platforms::IBilling::instance();
if (billing && billing->isSupported()) {
    billing->getItem("item_id");
    connect(billing, &Platforms::IBilling::sigPurchaseReceived, 
            [](const Platforms::Purchase &purchase) {
                // Handle purchase
            });
}
```

### Using Platform Tools

```cpp
#include "qaplatforms.h"

auto tools = Platforms::IPlatformTools::instance();
if (tools) {
    tools->setScreenDim(true);
    
    if (tools->getAccessToWriteInStorage()) {
        // Can write to storage
    }
    
    if (tools->getAccessToReadInStorage()) {
        // Can read from storage
    }
}
```

## Building

The library uses CMake for building. See the parent repository for build instructions.

```bash
mkdir build && cd build
cmake ..
make
```

## License

This library is distributed under the GPLv3 software license. See the [LICENSE](./LICENSE) file for details.

## Contributing

Contributions are welcome! Please read our [contributing guide](https://github.com/QuasarApp/.github/blob/main/CONTRIBUTING.md) before submitting pull requests.

## Support

For support and questions, please open an issue on the [QuasarApp GitHub organization](https://github.com/QuasarApp).


