---
.title = "IRQ Dispatch™",
.date = @date("2024-05-01T00:00:00"),
.author = "Felix \"xq\" Queißner",
.draft = false,
.layout = "product.html",
.tags = [ "product" ],
.custom = {
  .component = true,
  .image = "/img/chip-tqfp32.pov.png",
}
---

The IRQ Dispatch is a robust interrupt controller designed to manage up to 32 maskable interrupt sources. It consolidates multiple interrupt request (IRQ) lanes into a single output lane, facilitating efficient handling and prioritization of interrupts in embedded systems.

## Key Features

- **Support for Up to 32 IRQs**: Handles up to 32 different maskable interrupt sources, providing comprehensive coverage for various peripherals and processes.
- **IRQ Masking**: Allows selective masking of interrupts, ensuring critical tasks are not interrupted by less important ones.
- **IRQ Acknowledgment**: Provides functionality to acknowledge and clear IRQs, maintaining efficient interrupt management.
- **Level-Driven Interrupts**: Operates with level-driven IRQs, where an interrupt is active when the corresponding line is low.
- **Efficient Consolidation**: Merges multiple IRQ lanes into a single lane, simplifying the design and implementation of complex interrupt systems.

## Applications

- **Embedded Systems**: Ideal for managing multiple interrupt sources in embedded applications.
- **Real-Time Systems**: Ensures critical real-time processes are not disrupted by non-essential interrupts.
- **Industrial Control**: Enhances the reliability and efficiency of interrupt handling in industrial automation systems.

The IRQ Dispatch offers a versatile and efficient solution for managing multiple interrupt sources, ensuring reliable and orderly processing of interrupts in various applications.

## Functional Description

The IRQ Dispatch manages interrupt sources using two main registers, IRQ0 and IRQ1, each handling 16 IRQs (0-15 and 16-31 respectively). 

- **Active IRQs**: When an interrupt source is active (line is low), the corresponding bit in IRQ0 or IRQ1 is set. The output IRQ lane remains low until all active interrupts are acknowledged.
- **Acknowledgment**: To acknowledge an interrupt, write a 1 to the corresponding bit in the ACK0 or ACK1 registers. This action clears the interrupt and allows new interrupts to be processed.
- **Masking**: Interrupts can be masked by setting the corresponding bit in MASK0 or MASK1 registers. Masked interrupts will not trigger until they are unmasked (bit set to 0). Upon controller reset, all interrupts are masked by default.

## Usage

- **Reading Active IRQs**: Retrieve the current status of IRQs by reading the IRQ0 and IRQ1 registers. Active interrupts are indicated by bits set to 1.
- **Acknowledging IRQs**: Clear active interrupts by writing a 1 to the corresponding bits in the ACK0 or ACK1 registers.
- **Masking/Unmasking IRQs**: Control which interrupts are active by setting or clearing bits in the MASK0 and MASK1 registers.

## Documents & Downloads

### Documentation

- [Datasheet](https://downloads.ashet.computer/datasheets/irq.pdf)

<!-- ### Software & Sources

- [Verilog Implementation](/ACT-HC/src/branch/master/src/modules/i2c.v)
- [Driver Sources]() -->

For more information, please contact our sales team or visit our support page.
