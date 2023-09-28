# C language workbook

Here I'll add small exercises to practice the C language.

Currently, I'm using the following exercise resources:

* "The C Programming Language Book" (clp)
* PDS-1 courses (UFMG, 2023/2). (pds)

The folder structure is as following:

* `exercises/` - contain the exercise instructions and starting point material.
* `workspace/` - my personal resolution to the exercises.
* `utils/` - some utility resources that may help boilerplate.

## Aditional Resources

### Minimal TDD template

Simple template file with minimal test setup.

It leverages "assert.h", some custom macros and boilerplate stuctures.
And features a envvar reader to switch between the program flow and the test suite
  (within the same binary).
