# cpp-sample-bindings

## Table of Contents

+ [Summary](#summary)
+ [Reference](#reference)
+ [Features](#features)
+ [Getting started](#getting-started)

## Summary

A collection of sample code snippets demonstrating how to create bindings for various programming languages based on C++

## Reference

- [Python Bindings: Calling C or C++ From Python](https://realpython.com/python-bindings-overview/)

## Features

- [x] Modular code base
- [x] CI workflows for QA
- [x] Sample Python wrappers refering to C++ compiled source code   resulting in shared libraries 
- [ ] Sample Rust wrappers refering to C++ compiled source code resulting in shared libraries 
- [x] Sample Go wrappers refering to C++ compiled source code resulting in shared libraries 
- [x] Sample C# wrappers refering to C++ compiled source code resulting in shared libraries
- [ ] C++ audio module **(Optional, Experimental)**
- [ ] C++ video module **(Optional, Experimental)**

## Getting started

### Prerequisite

- Download and install [CMake from the official website](https://cmake.org/download/)  or trough a package manager
- Install [vcpkg from the official website](https://vcpkg.io/en/getting-started.html) or trough a package manager

### CMake

#### Unix

In order to compile the source code and link the binaries run in a Unix terminal:

```sh
cd devops/scripts/bash/
./compile_source_code.sh -CMakeToolchainFile <path to the vcpkg.cmake file>
```

In order to additionaly start the test executables in a Unix terminal: 

```sh
cd devops/scripts/bash/
./compile_source_code.sh -CMakeToolchainFile <path to the vcpkg.cmake file> -RunTests
```

#### Windows

In order to compile the source code and link the binaries run in a PowerShell terminal:

```sh
cd devops\scripts\ps1
.\compile_source_code.ps1 -CMakeToolchainFile <path to the vcpkg.cmake file>
```

In order to additionaly start the test executables in a PowerShell terminal: 

```sh
cd devops\scripts\ps1
.\compile_source_code.ps1 -CMakeToolchainFile <path to the vcpkg.cmake file> -RunTests
```

### Bindings

#### Python 

Run:

```sh
cd bindings/python
python main.py --path <path to libcore_wrapper.so>
```

#### C#

Run:

```sh
cd bindings/csharp
dotnet build
# Copy on unix systems the libcore_wrapper.so to the `bindings/c#/Mgtt.CoreWrapper/bin/Debug/net8.0` folder
dotnet run
```

#### Go

Run:

```sh
cd bindings/go
# Copy in the devcontainer the libcore_wrapper.so to this folder
export LD_LIBRARY_PATH=/workspaces/cpp-sample-bindings/bindings/go/libcore_wrapper.so:$LD_LIBRARY_PATH
go run main.go
```