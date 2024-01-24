#include <stdio.h>
#include <ctype.h>

long int my_strtol(const char *str, char **endptr, int base);

int main() {
    const char *str = "12345";
    char *endptr;
    long int result = my_strtol(str, &endptr, 10);

    if (endptr == str) {
        // No valid conversion
        printf("No valid conversion\n");
    } else {
        printf("Converted value: %ld\n", result);
    }

    return 0;
}

long int my_strtol(const char *str, char **endptr, int base) {
    // Implementation of your strtol-like function

    // Initialize variables
    long int result = 0;
    int sign = 1;

    // Skip leading whitespace
    while (isspace(*str)) {
        str++;
    }

    // Check for optional sign
    if (*str == '-' || *str == '+') {
        sign = (*str++ == '-') ? -1 : 1;
    }

    // Check for base prefix (0x for hex, 0 for octal)
    if (base == 0) {
        if (*str == '0') {
            str++;
            if (*str == 'x' || *str == 'X') {
                base = 16;
                str++;
            } else {
                base = 8;
            }
        }
    }

    // Main conversion loop
    while (isalnum(*str)) {
        int digit;

        // Convert character to digit
        if (isdigit(*str)) {
            digit = *str - '0';
        } else {
            digit = toupper(*str) - 'A' + 10;
        }

        // Check if digit is valid for the given base
        if (digit < 0 || digit >= base) {
            break;
        }

        // Update result
        result = result * base + digit;
        str++;
    }

    // Set endptr to the first character that is not part of the valid conversion
    if (endptr != NULL) {
        *endptr = (char *)str;
    }

    return sign * result;
}
