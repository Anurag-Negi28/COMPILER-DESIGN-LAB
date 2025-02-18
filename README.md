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
