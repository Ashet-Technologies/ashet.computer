# About the Ashet Home Computer

## The Vision

- A modern home computer
- Fully hackable system
- Fully understandable system
- Good enough for "daily tasks"
  - desktop os
  - browse internet (not "modern web")
  - write/read text document
  - builtin system documentation
  - scripting on-system
  - compiling off-systme
- Simple enough to be understood by a single person
  - As little layers as reasonable
  - As much layers as necessary
  - No "complex" protocols
    - No PCI(e)
    - No modern USB (stay with USB 1.1)
  - No complex electronics designs
    - No BGAs
    - Fixable by hand-soldering and wire-patching

## Audience

- Makers
- Hackers
- Demosceners
- Educators
- Students
- Self-Learnings

## Comparison with other projects

The following table shows a comparison to other "small" computers. It should help you get an idea where the Ashet Home Computer is in relation to other projects.

| Feature                      | Ashet                                                               | [Raspberry Pi 4](https://www.raspberrypi.com/products/raspberry-pi-4-model-b/specifications/)   | [Arduino Uno REV3](https://store.arduino.cc/products/arduino-uno-rev3) | [Neotron Pico](https://github.com/neotron-Compute/neotron-Pico)     | [Cody Computer](https://www.codycomputer.org/)          |
|------------------------------|---------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|------------------------------------------------------------------------|---------------------------------------------------------------------|---------------------------------------------------------|
| CPU Architecture             | Arm Cortex-M33 (32 bit)                                             | Arm Cortex-A72 (64 bit)                                                                         | ATmega328p (8 bit)                                                     | Arm Cortex-M0+ (32 bit)                                             | 6502                                                    |
| CPU Model                    | [Rapsberry Pi RP2350](https://www.raspberrypi.com/products/rp2350/) | [Broadcom BCM2711](https://www.raspberrypi.com/documentation/computers/processors.html#bcm2711) | [ATmega328P](https://www.microchip.com/en-us/product/atmega328p)       | [Rapsberry Pi RP2040](https://www.raspberrypi.com/products/rp2040/) | [W65C02S](https://wdc65xx.com/integrated-circuit)       |
| CPU Cores                    | 2                                                                   | 4                                                                                               | 1                                                                      | 2                                                                   | 1                                                       |
| CPU Clock                    | 150 MHz                                                             | 1.8 GHz                                                                                         | 16 MHz                                                                 | 133 MHz                                                             | 1 MHz                                                   |
| System Memory                | 8 MB                                                                | 1, 2, 4 or 8 GB                                                                                 | 2 KB                                                                   | 264 kB                                                              | 64 kB                                                   |
| Understandable               | ✅                                                                   | ❌                                                                                               | ✅                                                                      | ✅                                                                   | ✅                                                       |
| Modern I/O                   | ✅                                                                   | ✅                                                                                               | ❌                                                                      | ❌¹                                                                  | ❌                                                       |
| Modular Design               | ✅                                                                   | ❌                                                                                               | ❌                                                                      | ✅                                                                   | ✅²                                                      |
| Full Documentation Available | ✅                                                                   | ❌                                                                                               | ✅                                                                      | ✅                                                                   | ✅                                                       |
| Ethernet                     | ✅                                                                   | ✅                                                                                               | ❌                                                                      | ❌                                                                   | ❌                                                       |
| Parallax Propeller I/O Chip  | ✅ ([Propeller 2](https://www.parallax.com/propeller-2))             | ❌                                                                                               | ❌                                                                      | ❌                                                                   | ✅ ([Propeller 1](https://www.parallax.com/propeller-1)) |

¹Neotron Pico uses PS/2 for mouse/keyboard and VGA for video.

²Cody Computer has a single cartridge that can be added.
