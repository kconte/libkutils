# `libkutils`

A collection of common utility functions that I use throughout various projects
abstracted into a dynamically-linked library.

Only tested on GNU/Linux.

## Installation
```
make release
sudo make install
```

## Usage
`foo.c`:
```c
#include <kutils.h>

int main(int argc, const char **argv) {...}
```

Compilation:
```
cc foo.c -lkutils
```
