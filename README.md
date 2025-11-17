# Base Converter (GTK in C)

This project is a graphical application built with **GTK in C** that allows users to convert numbers between different bases: **binary, octal, decimal, and hexadecimal**.

---

## Features

- Convert a number from any base (2, 8, 10, 16) to another.
- Simple and user-friendly GUI built with GTK.
- Input validation with error messages for invalid numbers.

---

## How It Works

1. The program uses the C function `strtol()` to convert a number from the given base to decimal.
2. It then converts that decimal value to the target base (2, 8, 10, or 16).
3. The result is displayed in a GTK label when the user clicks the **Convert** button.

---

## Code Structure

- `convertBase()` → Handles base conversion logic.  
- `on_convert_clicked()` → GTK callback function for the Convert button.  
- `miniproject.h` → Contains function declarations.

---

## Usage

1. Compile the project using GCC with GTK libraries:

```bash
gcc -o base_converter main.c `pkg-config --cflags --libs gtk+-3.0`
\
./base_converter
