--Base Converter (GTK in C)

This project is a graphical application built with GTK in C that allows users to convert numbers between different bases (binary, octal, decimal, hexadecimal).

--Features

Convert a number from any base (2, 8, 10, 16) to another.

Simple and user-friendly GUI built with GTK.

Input validation with error messages for invalid numbers.

--How it works

The program uses the C function strtol() to convert a number from the given base to decimal.

Then, it converts that decimal value to the target base (2, 8, 10, or 16).

The result is displayed in a GTK label when the user clicks the Convert button.

--Code Structure

convertBase() → Handles base conversion logic.

on_convert_clicked() → GTK callback function for the Convert button.

miniproject.h → Contains function declarations.
