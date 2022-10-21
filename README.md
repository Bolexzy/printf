# _printf 📁
<img width="700"  alt="Printf" src="https://user-images.githubusercontent.com/74738413/197097747-74ea33cb-2c8f-4c5c-b62e-c1206bb5ae2b.png">

> _printf - Project at ALX_HOlBERTON School by
> **@Boluwatife O Emmanuel - @Akintola Habeeb**

The pair progrmming project is completed as part of the low-level programming and algorithm curriculum at ALX.
**_printf()** is a formatted output conversion **C** program. It produces a formatted string to the standard output (the display).

The program is a replica of the C standard library  function,`printf()`.

## Technologies 🖥
- C files are compiled using gcc 9.4.0 with with the flags (-Wall -Werror -Wextra -pedantic -std=gnu89).
- C files are written according to the C90 standard
- Tested on Ubuntu 20.04 LTS

## Synopsis 🔍
> Prototype
```
int _printf(const char *format, ...)
```
Where format is the first argument which is referred to as the message string and is always the first argument of printf(). It can contain special control characters and/or parameter conversion control characters.
> format tags prototype
```
%[flags][width][.precision][length]specifier
```
## Description 📒
The `_printf` prototype is defined in the `<main.h>` header file. When you use the `_printf()` function, it prints the string pointed out by the format to the standard output stdout. The format can also contain some specifiers that start with a % which are replaced by values of variables(accessed via the variable-length argument facilities of stdarg) for output.

To put it simply, they work as additional arguments to the `_printf()` function.
> **Return Value**

The function returns:
- The number of characters written if successful(excluding the terminating null byte used to end output to strings)
- A negative value, if failed

## Format Specifiers
Specifiers | Functions | Output
--- | --- | ---
c | `_printfChar` | The int argument is converted to an unsigned char
s | `_printfStr` | Prints a string of chars
% | `print_percent` | Prints the char % 	
d, i | `_printfInt` | Prints a signed decimal integer
S | `_printf_S` | Prints strings with special non-printable chars replaced by their ASCII value in hexadecimal (upper case, two characters).
o | `_printf_octal` | Prints an unsigned octal
u | `_printf_unsigned` | Prints an unsigned integer
x | `_printf_hex` | Prints an unsigned hexadecimal in lowercase.
X | `_printf_HEX` | Prints an unsigned hexadecimal in uppercase.
b | `_printfBin` | Prints a signed binary number.
r | `printf_rev` | Prints reversed strings of characters.
R | `printf_rot13` | Prints | Prints strings of characters to corresponding character in ROT13.

## Flag Characters
Flags | Description | Specifiers
--- | --- | ---
\+ | Prints a plus sign (+) when the argument is a positive number. In other case, prints a minus sign (-). | d, i
\(space) | Prints a blank space if the argument is a positive number | d, i
\# | Prints 0, 0x and 0X for o, x and X specifiers, respectively. It doesn't print anything if the argument is zero | o, x, X

## Length Modifiers
Length | Description | Specifiers
--- | --- | ---
l | Prints a long int or unsigned long int | i, d, o, u, x and X
h | Prints a short int or unsigned short int | i, d, o, u, x and X

## Examples
**1. Printing a character:**
  ```
  int main(void)
  {
      char ch = 'A';
     _printf("%c\n", ch);
     return (0);
  }
  ```
  Output: ```A```

**2. Printing the string of chars "Alx is awesome!":**
  ```
  int main(void)
  {
    _printf("Alx %s.", "is awesome!");
    return (0);
  }
  ```
  Output: ```Alx is awesome!```
  
**3. Printing an integer number:**
  ```
  int main(void)
  {
    int x = 45, y = 90;
    _printf("%d ", x);
    _printf("%i\n", x);
    return (0);
 }
 ```
 Output: ```45
               45```

**4. Printing a binary, octal and hexadecimal:**
```
  int main(void)
  {
    _printf("10 in binary is [%b], in octal is [%o] and in hexadecimal is [%x]", 10, 10, 10);
    return (0);
  }
  ```
  Output: ``10 in binary is [1010], in octal is [12] and in hexadecimal is [A]``
  
**5. Printing a string in ROT13:**
```
   int main(void)
   {
      _printf("%R\n", "Hello, World");
      return (0);
   }
   ```
   Output: ``dlroW ,olleH``
    

###### **Using flags and length tags:**
    
**1. Printing a positive and negative integer with their sign:**
```
 int main(void)
 {
    _printf("2 * 2 = %+d and 5 * -5 = %+i", 4, -25);
    return (0);
 }
 ```
 Output: ``2 * 2 = +4 and 5 * -5 = -25``
      
**2. Printing a long integer number and short integer number:**
```
  int main(void)
  {
      _printf("1 million as a long int is %ld, but as a short int is %hd", 1000000, 1000000);
      return (0);
   }
   ```
   Output: ``1 million as a long int is 1000000, but as a short int is 16960``
  
## File Descriptions
File | Description
--- | ---
`printf.c` | Main file that Performs Formatted Output Conversion And Print Data.
`main.h` | Header File for Saving Functions Prototypes.
`_putchar.c` | File handles char(s), write to stdout.
`conversion_handler.c` | File handles flags, width and length modifiers for non-custom conversion specifiers
`handlers.c` | Main handler file, handles conversion specifiers and format string.
`int_utils.c` | File handles integers operations.
`string_utils.c` | File handles string operations(chars)
`precision.c` | File handles precision from format string
`print_chars.c` | File handles char(s) print operations
`print_ints.c` | File handles integer(s) print operations
`print_radix.c` | File handles radix operations(o,b,x,X)
`man_3_printf` | File for functions manual page.

## Authors
- [Boluwatife O. Emmanuel](github.com/bolexzy)
- [Akintola Habeeb](github.com/horlami228)
