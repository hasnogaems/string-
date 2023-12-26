#include <stdio.h>
#include <strings.h>
#include <stdarg.h>
#include <math.h>
typedef struct flags{
    int integer;
    int string;
    int move_format;

} flags;

typedef struct flagscanf{
    flags base;
    char* regular;
} flagscanf;

int s21_sprintf(char *str, const char *format, ...);
char* write_string(flags Flags, va_list arg);
char* write_int(flags Flags, va_list arg);
flags parser(const char *format);
char*  concat_type(flags Flags, va_list arg);
int itoa(int, char* , int );
int s21sscanf(const char *str, const char *format, ...);
flagscanf scanfparser(const char *format);
char*  scanf_concat_type(flagscanf Flags, va_list arg);
