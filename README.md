# COMPILER-DESIGN-LAB

This repository contains various lab exercises for a Compiler Design course. Each lab folder contains different programs and their corresponding lex files.

## Repository Structure

### LAB3

- `a.exe`: Executable file for the lab exercise.
- `example.l`: Lex file for the lab exercise.
- `lex.yy.c`: Generated C file from the lex file.

### LAB4

- `lex.yy.c`: Generated C file from the lex file.
- `program1.exe`: Executable file for the first program.
- `program1.l`: Lex file for the first program.
- `program2.exe`: Executable file for the second program.
- `program2.l`: Lex file for the second program.
- `program3.exe`: Executable file for the third program.
- `program3.l`: Lex file for the third program.

### LAB5

- `lex.yy.c`: Generated C file from the lex file.
- `program1.exe`: Executable file for the first program.
- `program1.l`: Lex file for the first program.

### Root Directory

- `lex.yy.c`: Generated C file from the lex file.
- `main.c`: Main C file.
- `remove_trailing_ws.exe`: Executable file to remove trailing whitespaces.
- `remove_trailing_ws.l`: Lex file to remove trailing whitespaces.
- `weekday.exe`: Executable file for the weekday program.

## Lab Experiments

### LAB3: Basic Lexical Analysis

- **Experiment 1:** Lexical Analyzer for Identifiers and Keywords

### LAB4: Advanced Lexical Analysis

- **Experiment 1:** Lexical Analyzer for Arithmetic Expressions
- **Experiment 2:** Lexical Analyzer for Relational Operators
- **Experiment 3:** Lexical Analyzer for Logical Operators

### LAB5: Lexical Analysis for Specific Patterns

- **Experiment 1:** Lexical Analyzer for Days of the Week

### LAB6: Number Conversion Using Lex

- **Experiment 1:** Convert Numbers to Roman Numerals
- **Experiment 2:** Convert Roman Numerals to Decimal Numbers

### LAB7: Parser Implementation Using Yacc

- **Experiment 1:** Arithmetic Expression Parser
- **Experiment 2:** Symbol Table Management

### LAB8: Grammar Analysis

- **Experiment 1:** Elimination of Left Recursion
- **Experiment 2:** Computation of FIRST and FOLLOW Sets

### LAB9: Operator Precedence Parsing

- **Experiment 1:** Leading and Trailing Sets
- **Experiment 2:** Operator Precedence Parsing

## How to Run

1. Ensure you have the necessary tools installed (e.g., Flex, GCC).
2. Navigate to the appropriate lab directory.
3. Compile the lex file using Flex:
   ```sh
   flex example.l
   ```
4. Compile the generated C file using GCC:
   ```sh
   gcc lex.yy.c -o output.exe
   ```
5. Run the executable:
   ```sh
   ./output.exe
   ```

## License

This project is licensed under the MIT License.
