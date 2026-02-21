# ft_printf

> A lightweight, custom reimplementation of the C standard library's `printf()` function — built from scratch without relying on the standard library.

---

## Overview

`ft_printf` is a C project that replicates the core behavior of `printf()` using only low-level system calls and variadic function mechanics. No formatted output functions from the standard library are used — everything is handled manually, from integer-to-string conversion to hexadecimal formatting.

The result is a static library (`libftprintf.a`) that can be linked into any C project as a drop-in replacement for `printf()`.

---

## Features

Supported format specifiers:

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address (hexadecimal) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Literal percent sign |

---

## No Standard Library — By Design

This project intentionally avoids any formatted output functions from the C standard library. The only external functions used are:

- `write` — for raw output to file descriptors
- `malloc` / `free` — for memory management
- `va_start`, `va_arg`, `va_copy`, `va_end` — for variadic argument handling

Every conversion and formatting operation is implemented from the ground up.

---

## Installation

Clone the repository and build the library:

```bash
git clone https://github.com/<your-login>/ft_printf.git
cd ft_printf
make
```

This produces `libftprintf.a` at the root of the repository.

---

## Usage

Include the header and link the library when compiling your project:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    ft_printf("Pointer: %p | Hex: %x\n", ptr, 255);
    return 0;
}
```

```bash
gcc main.c -L. -lftprintf -o my_program
```

---

## Algorithm & Design Choices

The core logic follows a simple two-pass approach:

1. **Parsing** — The format string is scanned character by character. Regular characters are written directly via `write`. When a `%` is encountered, the next character is read to determine the conversion type.

2. **Dispatching** — A handler function is called for each specifier. Each handler extracts the appropriate argument from the `va_list` and writes the formatted output.

This design keeps the code modular and easy to extend. Each specifier is handled independently, making it straightforward to add new conversions without touching existing logic.

For numeric conversions (`%d`, `%u`, `%x`, `%X`), a recursive or iterative digit-extraction approach is used — no `sprintf` or `itoa` from the standard library.

For `%p`, the pointer is cast to `unsigned long` and printed with a `0x` prefix in lowercase hex.

---

## Makefile Rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Build the library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the library |
| `make re` | Full rebuild |

---

## Resources

- [printf(3) — Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic functions in C — cppreference](https://en.cppreference.com/w/c/variadic)
- [stdarg.h — GNU C Library](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

---

*This project was created as part of the 42 curriculum.*
