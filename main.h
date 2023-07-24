#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'

            // Handle conversion specifiers
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;

                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }

                case '%':
                    putchar('%');
                    count++;
                    break;

                default:
                    // If an unsupported specifier is used, print the '%'
                    // followed by the character as is.
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++; // Move to the next character in the format string
    }

    va_end(args);
    return count;
}

int main() {
    int count = _printf("Hello, %s! The character is %c%%.\n", "world", 'A');
    printf("Number of characters printed: %d\n", count);
    return 0;
}
