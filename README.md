# Types

> :x: _**Note:**_ this project is abandoned
>
> just assume all _intptr\_t_, _int`N`\_t_, ... are defined, and include `<stdbool.h>`/`<stdint.h>`, use `void *`/`char *`/`intptr\_t`/`size\_t`/`ptrdiff\_t` appropriately. then no need to use this

It's common situation to include various types such as bool, int, float, char, string, ... etc.

you might face some problems like the following:

- _int`n`\_t_ and its families are optional
- _INT`N`\_WIDTH_ and its families are not available until C20
- _intptr\_t_, _uintptr\_t_ is optional
- _**char**_ might be _**signed** char_ or _**unsigned** char_, depends on compiler
- _ptrdiff\_t_ and _size\_t_... what is what?

It provides way to use these more safety, easily, clearly, by include once, with minimum required headers!

- define _t\_i`n`_ to _int`n`\_t_, or its compatible type if possible
- define _INT`N`\_WIDTH_ and its families
- define _t\_isize_ and _t\_usize_ (_size\_t_, _ssize\_t_)
- define _t\_ic_ and _t\_uc_ - don't use _char_ for numeric type!

## Prerequisites

C99 or later required. (`<stdint.h>`, `<limits.h>`)

It uses POSIX header `<sys/types.h>` to use `ssize_t`, which is _**not** included in C standard_

### restrictions

**1 byte must be 8 bits** - Platforms where 1 byte is not 8 bits are not supported.

It requires `CHAR_BIT` (from `<limits.h>`) _MUST BE **8** EXACTLY_

## Features

### feature macro

- `FT_PEDANTIC` - don't define optionals unless explicitly required
- `FT_REQUIRE_*` - define `*`, error on failure - supported below
  - `T_I0` - type `t_i0` - same as `int8_t`
  - `T_I1` - type `t_i1` - same as `int16_t`
  - `T_I2` - type `t_i2` - same as `int32_t`
  - `T_I3` - type `t_i3` - same as `int64_t`
  - `T_I0` - type `t_u0` - same as `uint8_t`
  - `T_I1` - type `t_u1` - same as `uint16_t`
  - `T_I2` - type `t_u2` - same as `uint32_t`
  - `T_I3` - type `t_u3` - same as `uint64_t`
  - `INTMAX_WIDTH` - was not available until C20
  - `UINTMAX_WIDTH` - was not available until C20

### defined types

### defined macro constants

## Installation

Step: [install](#install)

### Install

1. copy `src/includes/ft` to your **include path**. It's all!

## Usage

### source

```c
#include <ft/types.h>
```

If you only need int types, include `ft/types/int.h` instead

```c
#include <ft/types/int.h>
```

### build

add libary path if not [install](#install)ed properly

```make
CFLAGS += -I/path/to/src/includes
```

no additional setting required!

## Contributing

Any PR is welcome if below is kept

- _**[DON'T COMMIT FILES WITH 42 HEADER NOT REMOVED](#remove-42-header)**_
- If possible, keep the [Norm](https://github.com/42School/norminette)

### pre-commit hook

Run `init.sh` to initialize git pre-commit hook.

```sh
sh init.sh
```

It will copy `hooks/pre-commit.sh` into `.git/hooks/pre-commit`, and set execute permission on it.

#### remove 42 header

File history is handled really great by git.

Just let git handle it, and stop polluting history :)

This pre-commit script will remove 42 header from `*.c` and `*.h` files

Alternate method: run shell command below **before every commit**, or never touch 42 header

```sh
find . -name '*.c' -o -name "*.h" -o -name "*.sh" -o -name Makefile \
| xargs -L1 sh hooks/scripts/42header-remover.sh
```
