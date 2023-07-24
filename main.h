#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - Structure containing flags to control certain characters
 * when a flag specifier is passed to the _printf() function.
 * @plus: Flag for the '+' character
 * @space: Flag for the ' ' character
 * @hash: Flag for the '#' character
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - Structure to choose the appropriate function
 * on the format specifier passed to the _print() function
 * @c: Format specifier
 * @f: Pointer to the correct printing function
 */

typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} printHandler_t;

/* Numeric printing functions */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* Base printing functions */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* Number conversion */
char *convert(unsigned long int num, int base, int lowercase);

/* Main printing function */
int _printf(const char *format, ...);

/* Function to retrieve the appropriate printing function */
int (*get_print(char s))(va_list, flags_t *);

/* Function to retrieve the appropriate flag */
int get_flag(char s, flags_t *f);

/* String and character printing functions */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* Helper write functions */
int _putchar(char c);
int _puts(char *str);

/* Custom printing functions */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* Address printing function */
int print_address(va_list l, flags_t *f);

/* Percentage printing function */
int print_percent(va_list l, flags_t *f);

#endif
