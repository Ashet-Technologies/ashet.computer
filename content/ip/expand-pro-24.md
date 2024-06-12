---
.title = "ExpandPro 24™",
.date = @date("2024-06-12T00:00:00"),
.author = "Felix \"xq\" Queißner",
.draft = false,
.layout = "product.html",
.tags = [ "product" ],
.custom = {
  .memory = true,
  .image = "/img/chip-tqfp44.pov.png",
}
---

The ExpandPro 24 by Ashet Technologies™ is an advanced Memory Management Unit (MMU) designed for efficient virtual to physical address translation. With features like 16-bit virtual addresses, 24-bit physical addresses, and configurable write-protection, it ensures robust memory management for complex systems.

## Key Features

- **Addressing**: 16-bit virtual and 24-bit physical addresses.
- **High Capacity**: 16 banks of 4096 bytes each, totaling a 64 kB address space.
- **Write Protection**: Configurable write-protection per page.
- **Fault Detection**: Handles access and write faults with dedicated fault registers.

## Functionality

- **Page Translation**: Uses 16 pages, each with 4096 bytes, to map virtual to physical addresses.
- **Fault Registers**: Logs access and write faults to enhance system reliability.

## Configuration

- **Page Descriptors**: Each 16-bit descriptor includes settings for enablement, write protection, and caching.
- **Fault Registers**: Indicate access and write faults.


## Documents & Downloads

### Documentation

- [Datasheet](https://downloads.ashet.computer/datasheets/mmu.pdf)

<!-- ### Software & Sources

- [Verilog Implementation](/ACT-HC/src/branch/master/src/modules/i2c.v)
- [Driver Sources]() -->

For more information, please contact our sales team or visit our support page.
