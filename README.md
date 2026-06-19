# ft_printf

> A reimplementation of the C `printf` function using variadic arguments.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![School](https://img.shields.io/badge/school-42%20Heilbronn-black.svg)
![Norm](https://img.shields.io/badge/norminette-passing-brightgreen.svg)

---

## About

**ft_printf** reproduces the behaviour of the standard C `printf` function from scratch. The project introduces variadic functions (`va_list`, `va_arg`, `va_start`, `va_end`) and handles a subset of the standard format specifiers without using the real `printf`.

---

## Supported Conversions

| Specifier | Output |
|---|---|
| `%c` | Single character |
| `%s` | String (`NULL` prints as `(null)`) |
| `%p` | Pointer address in `0x...` hex format |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hex integer (lowercase) |
| `%X` | Unsigned hex integer (uppercase) |
| `%%` | Literal percent sign |

---

## Structure

```
printf/
├── ft_printf.h         # Prototypes and includes
├── ft_printf.c         # Entry point — parses format string, dispatches conversions
├── conversion_check.c  # Routes each format specifier to the correct handler
├── ft_putchar.c        # Handles %c and %s (with NULL guard)
├── ft_putnbr.c         # Handles %d / %i / %u
└── ft_hexa.c           # Handles %x, %X, and %p via recursive hex conversion
```

---

## Usage

### Build

```bash
make
```

This produces `libftprintf.a`, which you can link into other projects.

### Link in another project

```makefile
PRINTF_PATH = path/to/printf
PRINTF      = $(PRINTF_PATH)/libftprintf.a

$(NAME): $(OBJS)
    $(MAKE) -C $(PRINTF_PATH)
    $(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_PATH) -lftprintf -o $(NAME)
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are student #%d.\n", "world", 42);
    ft_printf("Pointer: %p\n", (void *)main);
    ft_printf("Hex: %x | %X\n", 255, 255);
    ft_printf("Null string: %s\n", NULL);
    return (0);
}
```

Output:
```
Hello, world! You are student #42.
Pointer: 0x...
Hex: ff | FF
Null string: (null)
```

### Return value

`ft_printf` returns the total number of characters printed, or `-1` on write error — matching the behaviour of the standard `printf`.

---

## Implementation notes

- `ft_hexa` is a single recursive function handling `%x`, `%X`, and `%p`. It takes an `unsigned long` (to correctly handle 64-bit pointer sizes) and a flag for upper/lowercase.
- `%p` prepends `0x` via `ft_putstr` then calls `ft_hexa` for the address digits.
- `ft_putnbr` takes `long long` internally and handles `INT_MIN` as a hardcoded string to avoid undefined behaviour on negation.
- All write errors propagate upward and return `-1`.

---

## Makefile Targets

| Target | Description |
|---|---|
| `make` / `make all` | Compile `libftprintf.a` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and archive |
| `make re` | `fclean` + `all` |

---

## Notes

- No use of the real `printf` or any buffering functions.
- Written in compliance with the **42 Norm**.

---

*42 Heilbronn — Core Curriculum*
