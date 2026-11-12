# Platforms Library - Doxygen Documentation Guide

## Overview

The Platforms library provides cross-platform utilities for Android, iOS, macOS, Linux, and Windows. This library implements a unified interface for platform-specific operations.

## Documentation Status

✅ **Doxygen-style documentation has been implemented for all classes, interfaces, and functions.**

All source files in the `src/Library/src/` directory contain comprehensive Doxygen documentation including:

- Class descriptions with detailed explanations
- Method documentation with parameters, return values, and notes
- Signal documentation for Qt-based classes
- Struct documentation for data types
- Function documentation for utility functions

## Documentation Configuration

The documentation is generated using Doxygen with the configuration file `doxygen.conf`.

### Building Documentation

To generate documentation, run:

```bash
doxygen doxygen.conf
```

Or using CMake:

```bash
cmake .
make doc
```

### Documentation Output

The generated documentation will be placed in the `docs/` directory.

## Documented Components

### Public Interface

#### Main Header: `qaplatforms.h`
- **Namespace `Platforms`** - Contains all platform utilities
- **`init()`** - Initialize the Platforms library
- **`version()`** - Get the current library version

#### IBilling Interface (`ibilling.h`)
- **`Purchase` struct** - Contains purchase information (id, token, count)
- **`IBilling` class** - Base interface for in-app purchases
  - `instance()` - Get billing instance for current platform
  - `init()` - Initialize the billing system
  - `getItem(itemID)` - Request purchase of an item
  - `isSupported()` - Check if billing is supported
  - `sigPurchaseReceived(purchase)` - Signal emitted when purchase is completed

#### IPlatformTools Interface (`iplatformtools.h`)
- **`IPlatformTools` class** - Base interface for platform utilities
  - `instance()` - Get platform tools instance
  - `setScreanDim(enable)` - Set screen dim mode
  - `getAccessToWriteInStorage()` - Request write storage access
  - `getAccessToReadInStorage()` - Request read storage access

### Platform Implementations

#### Android
- **`AndroidBilling`** (`androidbilling.h/cpp`) - Android-specific billing implementation
- **`AndroidPlatformTools`** (`androidplatformtools.h/cpp`) - Android platform utilities
- **`JavaProvider`** (`javaprovider.h/cpp`) - JNI bridge to Android Java layer

#### iOS
- **`IOSPlatformTools`** (`iosplatformtools.h/cpp`) - iOS platform utilities

#### macOS
- **`OSXPlatformTools`** (`osxplatformtools.h/cpp`) - macOS platform utilities

#### Linux
- **`LinuxDesktopPlatfomTools`** (`linuxdesktopplatfomtools.h/cpp`) - Linux desktop utilities

#### Windows
- **`WindowsDesktopPlatformTool`** (`windowsdesktopplatformtool.h/cpp`) - Windows desktop utilities

### Documentation Quality

The documentation follows Doxygen best practices:

1. **@file directive** - Describes the purpose of each header file
2. **@brief directive** - Provides a one-line summary
3. **@details directive** - Offers detailed explanations
4. **@param directive** - Documents function parameters
5. **@return directive** - Documents return values
6. **@note directive** - Provides important notes and warnings
7. **@since directive** - Indicates version introduction
8. **@example directive** - Shows usage examples

## License

This project is licensed under GPL v3.

## Contributing

For contributions to the documentation, please ensure:
- All public classes, interfaces, and functions have documentation
- Documentation follows Doxygen style
- Examples are accurate and up-to-date