# Roman Numeral Converter

## Overview

This C++ program serves as a Roman numeral conversion tool, designed to accept Roman numeral inputs and output their corresponding values in standard Arabic notation. It adheres to the conventions of the Roman numeral system, considering digit order, the number of occurrences, and the use of prefixes.

## Roman Numeral Conventions:

- **M = 1000**
- **D = 500**
- **C = 100**
- **L = 50**
- **X = 10**
- **V = 5**
- **I = 1**

**Digit Order:**
Roman digits are written in non-ascending order, and digit values are added to produce the represented value, except for prefixes.

**Number of Occurrences:**
No more than three occurrences of M, C, X, or I may appear consecutively, and no more than one D, L, or V may appear at all.

**Prefixes:**
The digits C, X, and I can be used as prefixes, with their value subtracted from the accumulated value under specific conditions.

## Examples:

- **MCMLXXXVIII = 1988**
- **MCMXCIX = 1999**
- **CCCXXXIX = 339**

## Usage

1. **Compilation:**
   - Compile the program using a C++ compiler.
     ```bash
     g++ RomanNumeralConverter.cpp -o RomanNumeralConverter
     ```

2. **Execution:**
   - Run the compiled program.
     ```bash
     ./RomanNumeralConverter
     ```
   - Enter a Roman numeral when prompted.

## Contributing

Feel free to contribute to the improvement of this Roman Numeral Converter. If you encounter any issues or have suggestions, please open an issue.

## License

This project is licensed under the [MIT License](LICENSE).
