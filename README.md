# greet

`greet` will prompt a user for a name to `stdout`, then dynamically read a name
from `stdin`, and print the result back to `stdout`.

![Interactice name read](.img/greet.gif)

# Dependencies

* ISO / IEC 9899:1999 (C99) compiler
  - GNU Compiler Collection (gcc)
  - clang
  - Tiny C Compiler (tcc)
* ISO / IEC 9899:1999 (C99) C library
  - GNU libc (glibc)
  - musl-libc
* IEEE / Open Group 1003.1-2017 (POSIX.1-2017) `make (1p)` utility
  - GNU Make (`gmake`)
  - BSD Make (`bmake`)
  - Public Domain POSIX Make (`pdpmake`)
* IEEE / Open Group 1003.1-2017 (POSIX.1-2017) `c99 (1p)` utility

# Build

To build `greet`, run

```
$ make
```

or

```
$ make all
```

## Cleaning source

To clean the source directory, run

```
$ make clean
```

# Install

To install `greet`, build `greet` then run

```
# make install
```

## Uninstall

To uninstall `greet`, run

```
# make uninstall
```

# Documentation

For additional documentation, see

```
$ man greet
```

## Examples

Enter name interactively.

```
$ greet
Enter name: Foo
Hello, Foo!
```

Pipe string into `greet`.

```
$ printf "Foo" | greet
Hello, Foo!
```

# License

SPDX-License-Identifier: `Unlicense`

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <[http://unlicense.org/](http://unlicense.org/)>
