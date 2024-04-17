# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.5.0] - 17-04-2024

### Added

- [Feature] C++ audio module **(Optional, Experimental)**. **NOTE:** Does not include working bindings. Attempts were made for [audio_wrapper.py](./bindings/python/audio_wrapper.py)

## [0.4.0] - 16-04-2024

### Added

- [Feature] Sample Rust wrappers utilizing [cxx](https://crates.io/crates/cxx) and refering to C++ source code

## [0.3.0] - 16-04-2024

### Added

- [Feature] Sample Go wrappers refering to C++ compiled source code resulting in shared libraries

### Fixed 

- comment out lines in [install-dependencies.sh](.devcontainer/go/scripts/install-dependencies.sh) bash scripts

## [0.2.0] - 15-04-2024

### Added

- [Feature] Sample C# wrappers refering to C++ compiled source code resulting in shared libraries

### Fixed 

- Rename, comment out lines and install missing apt dependencies in `install-dependencies.sh` bash scripts

## [0.1.0] - 15-04-2024

### Added

- [Feature] Initial project setup including `devcontainer.json` files, `C core module` and Python bindings
- [Feature] Modular code base
- [Feature] CI workflows for QA
- [Feature] Sample Python wrappers refering to C++ compiled source code   resulting in shared libraries 