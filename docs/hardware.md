# Hardware

## Architecture

![A block diagram of the whole system, showing how mainboard, backplane and expansion cards are interconnected](assets/architecture.svg)

- Modular concept
- Each unit is encapsulated function
- Interfaces between components is a well-defined "public" interface

## Mainboard

![A block diagram of the mainboard showing the architecturial components](assets/mainboard.svg)

- Contains everything necessary for basic operation
  - CPU
  - RAM
  - Flash
- Dedicated I/Os
  - USB
  - Ethernet
- Integrated Debugger
  - On-chip-debugger
  - High-speed Debug UART (>= 1 MBaud)
- Can be used standalone

## Backplane

![A block diagram of the backplane showing the architecturial components](assets/backplane.svg)

- Interconnect between Mainboard and Expansion Cards
- Southbridge Concept
  - One CPU core per socket
  - 64k RAM per socket
  - 8 true general purpose I/Os
- Software-defined backplane

## Expansion Cards

![A block diagram of an expansion board showing the architecturial components](assets/expansion.svg)

- EEPROM
- Standard I/Os
  - GPIOs
  - I²C
- Special Cases
  - Video Expansion Card: Dedicated output lanes for high-bandwidth graphics data
  - Audio Expansion Card: Dedicated I/O lanes for low-latency I²S
