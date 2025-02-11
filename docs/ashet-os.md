# Ashet OS

## The Vision

- Runs on low-end machines
  - 8 MB of RAM must be enough
- Good enough to be actually useful
- Simple enough to be hacked on
- Portable to multiple platforms

## Features

- Multi-platform OS from the beginning
  - RISC-V 32
  - Arm Cortex-M
  - x86 PC
- Asynchronous Syscall Design
- Multi-Tasking
  - Processes
  - Multi-Threading
  - IPC
  - Shared Memory
  - Pipes
  - Sync Primitives
- Graphics API
  - Built-in GUI support
  - Rendering API
    - *Can* be GPU-accelerated
- Networking
  - TCP and UDP sockets
- Filesystem
  - Multiple Filesystems supported

## The Design

- No security focus at all
  - Makes the OS approachable and understandable
  - Mitigations create complicated scenarios
  - Removal of CPU security features allows some neat simplifications
- Portable from the start
  - Decision: 32-bit only
  - Makes platform-specific code be properly modularized
- Cooperatively scheduled
  - Does not require interrupts
  - Makes the better design portable
  - Has obvious drawback: One bad actor kills the OS
    - Accepted as it is not meant for "serious work"
  - Simplifies the scheduler and the overall software
- Monolithic design
  - Simplifies most code
- Modern design
  - No "working directory"
  - Not unix philosophy
    - Specialized syscalls for specialized tasks
- GUI
  - Mix of Win32, Wayland, X11
  - Desktops, Windows, Widgets
  - Not tied to screens
  - Allows userland implementations

