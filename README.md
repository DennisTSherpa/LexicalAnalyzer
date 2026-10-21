# Lexical Analyzer for Eagle

A scanner for the Eagle programming language, generated with Flex in C++ mode. It turns Eagle source code into a stream of tokens: keywords, type declarators, operators, identifiers, and integer, rational, and string literals. It prints each token as it reads it.

## Features

- Reads from a file given as an argument, or from stdin if no file is given.
- Discards whitespace and `#` comments.
- Removes the enclosing quotes from string literals inside the scanner.
- Prints the value of each data token:
  - identifiers and strings print as text;
  - integers are converted with `std::stol`;
  - rationals are converted with `std::stod`.
- Defines tokens as an `enum Token` starting at 1, because 0 means end of input.

## Files

| File | Purpose |
|---|---|
| `eagle.lex` | Flex specification: one regex and action per token |
| `eagle.h` | `Token` enumeration, shared by the scanner and `main` |
| `main.cpp` | Runs `yyFlexLexer::yylex` in a loop and prints each token |
| `makefile` | Builds `eagle_scanner`; `make clean` removes all build files |

## Build & Run

Requires `flex` and a C++ compiler. On macOS, install flex with `brew install flex`.

```bash
make
./eagle_scanner input_pa2.txt   # read from a file
./eagle_scanner                 # read from stdin (Ctrl-D to end)
```

## Testing

```bash
chmod u+x test_pa2.sh
./test_pa2.sh
```

## Author

Dennis T Sherpa, Compilers, Boston College (Fall 2026)
