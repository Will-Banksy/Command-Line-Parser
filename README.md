# Command Line Parser

This is a simple command line parser library written in C++

It could probably do with more work but it should work pretty well as it is

## Compiling

### Shared Library

Simply run cmake and make (or ninja or whatever you want to use)

First make a build directory in the project root directory and enter that, then:

```bash
cmake ..
make
```

### Static Library

Simply run cmake (but setting the option CLI_PARSER_STATIC to ON) and make (or ninja or whatever you want to use)

First make a build directory in the project root directory and enter that, then:

```bash
cmake -DCLI_PARSER_STATIC=ON ..
make
```
