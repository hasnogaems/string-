#include <stdio.h>
#include <strings.h>

typedef struct flags{
    int integer;
    int string;


} flags;

int s21_sprintf(char *str, const char *format, ...);
char* write_string(flags Flags, va_list arg);
char* write_int(flags Flags, va_list arg);
flags parser(const char *format);
char*  concat_type(flags Flags, va_list arg);