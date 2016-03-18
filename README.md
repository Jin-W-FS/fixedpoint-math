# What is it
Real number mathematics with fixed point(against the "float point") numbers

# How to use
Modify the header file fixedpoint.h, set up its base type and decimal bits; include it.

# Supported languages
The lib is written for C, althrough the main() test function is written in C++.

# Features
All the calculation is limited within the length of base-type --
I don't make the assumption that there exists a type which doubled its length.
Very important when your environment lacks support for int64_t or __int128_t!
