# Command Line Parser

This is a simple command line parser library written in C++

It could probably do with more work but it should work pretty well as it is

## Compiling

### Static Library

Simply run cmake and make (or ninja or whatever you want to use)

First make a build directory in the project root directory and enter that, then:

```bash
cmake ..
make
```

### Shared Library

Run cmake with the option -DSharedLib and then make or whatever

First make a build directory in the project root directory and enter that, then:

```bash
cmake -DSharedLib=ON ..
make
```