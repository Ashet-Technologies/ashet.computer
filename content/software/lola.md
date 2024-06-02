---
.title = "LoLa Scripting",
.date = @date("2024-06-01T00:00:00"),
.author = "Felix \"xq\" Queißner",
.draft = false,
.layout = "product.html",
.tags = [ "software" ],
.custom = {
  .devtool = true,
  .image = "/img/software/lola.png",
}
---

LoLa is an embeddable programming language for game scripting,
Its primary design focus is an easy-to-understand feature set and an implementation that allows perfect control of the script execution.

The language runtime and compiler are cross-platform and is available for MacOS, Windows and Linux. The compiler and runtime itself are platform independent and will work on any platform.

## Features

### Easy-to-learn syntax

The syntax of the LoLa language is similar to languages like JavaScript and it's familiar to most programmers.
Non-programmers can easily learn the block-oriented syntax with less than 20 keywords and only 20 operators.

### Protection against bad code

The LoLa runtime protects the host application from misbehaving user code by slicing code execution in controllable chunks.
Even endless loops will eventually return to the host! Out-of-memory problems will be catched by the use of host-controlled allocators.

### Asynchronous execution

LoLa code is designed to suspend at any time and return control back to the host. In this example, WaitForKey will immediately return control to the host, eating no CPU time until the host decides that the script should continue.
Most other scripting languages don't allow that behaviour, enforcing multithreading or other workarounds.

### Fully serializable state

The LoLa runtime is designed to be saved to disk at any point not executing any code. This means that you can let your script execute for 1000 instructions, save the runtime state to disk and resume execution a week later on another computer, not having any problems with script resumption. This is especially useful for games which often want to embed the state of their scripts into the save files.

## Documentation

The following documents are available:

* [Language Documentation](https://lola.random-projects.net/docs/language.htm)
* [Standard Library Documentation](https://lola.random-projects.net/docs/standard-library.htm)
* [Runtime Library Documentation](https://lola.random-projects.net/docs/runtime-library.htm)
* [Library Code Documentation](https://lola.random-projects.net/docs/index.html#root)
* [Intermediate Language Description](https://lola.random-projects.net/docs/intermediate-language.htm)
* [LoLa Binary Module Format (`.lm`)](https://lola.random-projects.net/docs/module-binary.htm)

You can also check out these LoLa example source files on GitHub:

* [Reversing an array](https://github.com/ikskuh/LoLa/blob/master/examples/lola/reverse-array.lola)
* [Fibonacci Sequence](https://github.com/ikskuh/LoLa/blob/master/examples/lola/fib-iterative.lola)
* [BubbleSort](https://github.com/ikskuh/LoLa/blob/master/examples/lola/bubble-sort.lola)
* [Ingame script](https://github.com/ikskuh/LoLa/blob/master/examples/lola/game-code.lola)
* [Forth-like toy interpreter](https://github.ikskuh/MasterQ32/LoLa/blob/master/examples/lola/forth.lola)

## Releases

![CI status](https://github.com/MasterQ32/LoLa/workflows/Build/badge.svg)

LoLa currently has no binary releases. Source code and build instructions can be gathered at [github.com/ikskuh/LoLa](//github.com/ikskuh/LoLa).
