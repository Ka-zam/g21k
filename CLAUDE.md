# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is **g21k**, an open-source cross-compiler toolchain for **Analog Devices Sharc DSP (ADSP-21xxx) processors**. It consists of two main components:

- **GCC (g21k)** - Cross-compiler based on GCC 2.3.3 for Sharc/21k DSP architecture
- **Binutils** - Binary utilities: assembler (asm21k), linker (ld21k), memory loader (mem21k), COFF dump (cdump21k)

The code originates from Analog Devices and has been patched for Unix/Linux compatibility. Licensed under GPL v2+.

## Build Commands

### Building GCC Compiler

```bash
# Build Sharc compiler (g21k)
make build-g21k
make install-g21k    # requires root

# Build 21csp variant (g21c)
make build-g21c
make install-g21c

# Build 21xx variant (g21)
make build-g21
make install-g21

# Install man pages
make install-man

# Clean
make clean           # Remove build artifacts
make distclean       # Also remove config files
```

### Building Binutils

```bash
cd binutils
./configure
make dep             # Generate dependencies (required first time)
make
make install         # requires root
```

### Build Requirements

- C compiler (gcc)
- GNU bison (parser generator)
- GNU gperf (perfect hash generator)
- Standard Unix tools (make, ar, ranlib)

## Architecture

### Directory Structure

```
gcc/                    # GCC compiler source
├── g21k/               # Main Sharc/21k compiler (~268 .c files)
│   ├── configure       # Autoconf script
│   ├── Makefile        # Complex GCC build
│   └── config/         # Architecture configs (21k, 21csp, 21xx)
├── g21xx/              # 21xx variant compiler
├── adiach/             # ADI ACH (Architecture Config Header) parsing
└── adi_dsp/            # DSP architecture libraries

binutils/               # Binary utilities
├── app/                # asm21k assembler application
├── asm/                # Low-level assembler (a21000)
├── lib/                # Shared libraries (coff_io, achparse)
├── ldr/                # mem21k memory loader
├── link/               # ld21k linker
├── cdump/              # COFF dump utility
└── doc/                # Man pages
```

### Key Concepts

- **Target architectures**: 21k (Sharc), 21csp, 21xx - selected via `--target` configure flag
- **COFF format**: Uses Sharc-specific COFF object file format
- **ACH files**: Architecture Configuration Headers define processor-specific features
- **ADI_DSP environment**: Default installation paths assume `/usr/local/21k/`

## Important Notes

- **32-bit only**: Code uses assumptions about pointer/int sizes; will not work on 64-bit without modification
- **Legacy codebase**: Based on GCC 2.3.3 (1990s era) - expect older C style and patterns
- **Patches**: `gcc.pch` and `binutils.pch` contain Unix/Linux compatibility fixes
- **Tested on**: Linux/i386 primarily

## Installed Tools

| Tool | Description |
|------|-------------|
| g21k | C compiler for Sharc/21k |
| asm21k | Assembler |
| ld21k | Linker |
| mem21k | Memory loader (LDR format) |
| cdump21k | COFF object file dump |
| a21000 | Assembler preprocessor (in /usr/local/21k/etc) |
