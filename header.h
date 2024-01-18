#include <stdio.h>
#include <strings.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
typedef long unsigned s21_size_t;
#define S21_NULL ((void *)0)
typedef struct flags{
    int integer;
    int string;
    int decimal_octal_hex;
    int move_format;
    int e;

} flags;

typedef struct flagscanf{
    flags base;
    int fspace, fminus, fplus, fsharp, fzero;
    
    char* regular;
} flagscanf;

typedef struct {
    int is_int;
    int is_hex;
    int is_octal;
    int is_scientific;
} number_type;

int s21_sprintf(char *str, const char *format, ...);
char* write_string(flags Flags, va_list arg);
char* write_int(flags Flags, va_list arg);
void sscanf_write_e(va_list arg, const char** source);
flags parser(const char **format, flags Flags);
char*  concat_type(flags Flags, va_list arg);
int itoa(int, char* , int );
int s21sscanf(const char *str, const char *format, ...);
void scanfparser_spec(const char *format, flagscanf*);
void scanf_concat_type(flagscanf Flags, va_list arg, const char** source);                  
flagscanf scanfparser_flags(const char** format);
int* scanf_write_decimal_octal_hex(va_list arg, const char** source);
int convert_to_dec(int input, int base);
float scientific_to_float(char* string);
long double char_to_dec(int* i, char str[]);
int is_int_f(char);
long double exponent_f(char exp[], float pre_plus_post);
