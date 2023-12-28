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
    int move_format;

} flags;

typedef struct flagscanf{
    flags base;
    int fspace, fminus, fplus, fsharp, fzero;
    
    char* regular;
} flagscanf;

int s21_sprintf(char *str, const char *format, ...);
char* write_string(flags Flags, va_list arg);
char* write_int(flags Flags, va_list arg);
flags parser(const char **format, flags Flags);
char*  concat_type(flags Flags, va_list arg);
int itoa(int, char* , int );
int s21sscanf(const char *str, const char *format, ...);
void scanfparser_spec(const char *format, flagscanf*);
char*  scanf_concat_type(flagscanf Flags, va_list arg);
void scanfparser_flags(const char *format, flagscanf* Flags);
