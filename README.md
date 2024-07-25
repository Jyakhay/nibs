# NIBS (Nebula | Inheritance-Based Serialization)
An inheritance based C++17 serialization library.

# Contents

1. [Context](#context)
2. [Capabilities](#capabilities)
3. [Cloning and Compiling](#cloning-and-compiling)\
3.1 [Cloning](#cloning)\
3.2 [Compiling](#compiling)
4. [Dependencies](#dependencies)

## Context
NIBS (Nebula Inheritance-Based Serialization) was originally created for use within a proprietry game engine of mine named Nebula. 

## Capabilities
NIBS is capable of serializing data in 2 different formats:
- Json
- Binary

in both compressed and uncompressed forms.

The number of formats however may be extended through using the IArchive interface.

NIBS currently supports the serialization of the following STL types:
- std::string
- std::vector
- std::unordered_map
- std::map

## Cloning and Compiling

### Cloning

The NIBS repository may be cloned with the following [git](https://git-scm.com/) command:
```git
git clone https://gitub.com/Jyakhay/nibs.git --recurse-submodules
```

### Compiling

NIBS uses the [CMake](https://cmake.org/) build system due to its cross-platform capabilities.

Steps to build the nibs project:
1. Open a command line inside a build directory which must be located at the root of the repository.
2. Enter the following command: ```cmake ..```

## Dependencies

- [RapidJson](https://github.com/Tencent/rapidjson) - Used for Json serialization.
- [zlib](https://github.com/madler/zlib) - Used for data compression.