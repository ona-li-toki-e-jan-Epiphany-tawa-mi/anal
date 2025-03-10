# anal

S(a)fety-Ta(n)t(a)mount C (L)ibrary.

## Synopsis

Adds a variety of extra functions and what-not for making C a wee bit safer.

Currently just a couple macros to enable more compiler warnings.

## Usage

Place `#define ANAL_IMPLEMENTATION` in one, and only one, C file before you
include this file to create the implementation.

I.e.:

```c
#define ANAL_IMPLEMENTATION
#include "anal.h"
```

## SOME !!HOT!! TIPS

Enable a lot of the warnings your C compiler supports.

In GCC, Clang, and zig cc:

- -Wall - A bunch of warnings.
- -Wextra - A bunch more warnings.
- -Wpedantic - Even more warnings.
- -Wconversion - Warn on narrowing type conversions.
- -Wswitch-enum - Warn when a switch() on an enum does not use all enum values. Good for refactoring and large code bases.
- -Wmissing-prototypes - Warn when a function does not have a prototype (i.e.: void function(void) { ... }, but no void function(void); before it,) OR is not declared static (i.e.: static void function(void) { ... }.) Good for refactoring and large code bases.

LISTEN TO AND FIX THE WARNINGS!!! --^

Set up unit/integration/whatever tests and run all of them with Valgrind's
Memcheck [https://valgrind.org](https://valgrind.org/) to identify memory leaks.

Make everything you can const so you can be sure you don't modify anything you
don't need to, or more importantly, shouldn't.

Mark any functions that allocate memory with the function to free that memory,
.i.e:

```c
// Deinitialize with thing_free().
void* thing_alloc(size_t bytes) { ... }
```

Mark the usages of any functions that return allocated memory with the function
to free that memory, i.e.:

```c
char *const buffer = malloc(256); // Must free().
```

Set a pointer to NULL after freeing it. Many functions have defined behavior on
NULL pointers, so if you accidentally use it again you'll have some protection
agains use-after-frees. I.e.:

```c
free(pointer);
pointer = NULL;
```

Please note that these tips are very anal ;). That is the point.
