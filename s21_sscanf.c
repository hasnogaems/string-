#include "s21_sscanf.h"

void  decrese_width(params *param) {
  if (param->width != -1) param->width--;
}

void width_function(const char *format, int *i, int *width) {
  int j = *i;
  while (format[j] <= 57 && format[j] >= 48) {
    *width = *width * 10 + (format[j] - '0');

    j++;
  }

  *i = j;
}

void format_length(const char *format, int *i, params *param) {
  param->length[0] = '\0';
  param->length[1] = '\0';

  int j = *i;
  if (format[j] == 'h') {
    param->length[0] = 'h';
    j++;
  } else if (format[j] == 'l') {
    param->length[0] = 'l';
    j++;
    if (format[j] == 'l') {
      param->length[1] = 'l';
      j++;
    }
  } else if (format[j] == 'L') {
    param->length[0] = 'L';
    j++;
  }
  *i = j;
}

void set_params(params *param, const char **format, int *i) {
  width_function(*format, i, &(param->width));
  if (param->width == 0) {
    param->width = -1;
    param->flag_data_failed = 0;
  }

  format_length(*format, i, param);
}

long double chr_to_dec(int *i, const char **str, params *param) {
  long double result = 0.0;

  while (**str >= 48 && **str <= 57 &&
         (param->width > 0 || param->width == -1)) {
    (*i)++;
    result *= 10;
    result += **str - '0';
    (*str)++;
    param->flag_data_failed = 0;

    decrese_width(param);
  }
  return result;
}

long int set_sign(const char **str, params *param) {
  long int sign = 1;
  if (**str == '+' && (param->width > 0 || param->width == -1)) {
    (*str)++;
    decrese_width(param);
  } else if (**str == '-' && (param->width > 0 || param->width == -1)) {
    sign = -1.0;
    (*str)++;
    decrese_width(param);
  }
  return sign;
}

int e_check(const char **str, float *scale, params *param) {
  int e_value = 0;
  const char *start_str = *str;
  if ((**str == 'e' || **str == 'E') &&
      (param->width > 0 || param->width == -1)) {
    *scale = 10.0;
    (*str)++;
    decrese_width(param);
    if (**str == '+' && (param->width > 0 || param->width == -1)) {
      (*str)++;
      decrese_width(param);
    } else if (**str == '-' && (param->width > 0 || param->width == -1)) {
      (*str)++;
      *scale = 0.1;
      decrese_width(param);
    }
    if (!(**str >= 48 && **str <= 57)) {
      *scale = 0;

      *str = start_str;
    } else {
      while (**str >= 48 && **str <= 57 &&
             (param->width > 0 || param->width == -1)) {
        e_value *= 10;
        e_value += **str - '0';
        (*str)++;
        decrese_width(param);
      }
    }
  }
  return e_value;
}

int counter(const char *restrict s, params const *param) {
  int i = 0;

  while ((*(s + i) != ' ' && *(s + i) != '\0' && *(s + i) != '\t' &&
          *(s + i) != '\n') &&
         (i < param->width || param->width == 0))

  {
    i++;
  }

  return i;
}

long long int s21_atoi(const char **restrict s, params *param) {
  param->flag_data_failed = 1;
  const char *start_str = *s;
  long long int sign = 1;

  if (**s == '-') {
    sign = -1;
    (*s)++;
    decrese_width(param);
  } else if (**s == '+') {
    (*s)++;
    decrese_width(param);
  }
  int i;
  long long int n = 0;

  for (i = 0; (*(*s + i) >= 48 && *(*s + i) <= 57) &&
              (param->width > 0 || param->width == -1);
       ++i) {
    n = (n * 10) + (*(*s + i) - '0');
    decrese_width(param);
    param->flag_data_failed = 0;
  }
  *s = (*s) + i;
  if (param->flag_data_failed == 1) *s = start_str;

  return n * sign;
}

void case_s(const char *s, va_list *a, int count, const params *param) {
  if (param->asterisk != 1) {
    char *arg_str = va_arg(*a, char *);

    if (param->width > 0 && param->width < count) {
      s21_strncpy(arg_str, s, param->width);
      arg_str[param->width] = '\0';
    } else {
      s21_strncpy(arg_str, s, count);
      arg_str[count] = '\0';
    }
  }
}

void case_d(params *param, const char **s, va_list *a) {
  if (param->length[0] == 'l' && param->length[1] != 'l') {
    long int arg1 = s21_atoi(s, param);
    if (param->asterisk != 1 && param->flag_data_failed == 0) {
      long int *arg = va_arg(*a, long int *);
      *arg = arg1;
    }
  } else if (param->length[0] == 'l' && param->length[1] == 'l') {
    long long int arg1 = s21_atoi(s, param);
    if (param->asterisk != 1 && param->flag_data_failed == 0) {
      long long int *arg = va_arg(*a, long long int *);
      *arg = arg1;
    }
  } else if (param->length[0] == 'h') {
    int arg1 = s21_atoi(s, param);
    if (param->asterisk != 1 && param->flag_data_failed == 0) {
      short int *arg = va_arg(*a, short int *);
      *arg = (short int)arg1;
    }
  } else {
    int arg1 = s21_atoi(s, param);
    if (param->asterisk != 1 && param->flag_data_failed == 0) {
      int *arg = va_arg(*a, int *);
      *arg = arg1;
    }
  }
}

void case_u(params *param, const char **s, va_list *a) {
  if (param->length[0] == 'l') {
    unsigned long int arg1 = (unsigned)s21_atoi(s, param);
    if (param->asterisk == 0 && param->length[1] != 'l') {
      unsigned long int *arg = va_arg(*a, unsigned long int *);
      *arg = arg1;
    }
  } else if (param->length[0] == 'l' && param->length[1] == 'l') {
    unsigned long long int arg1 = s21_atoi(s, param);
    if (param->asterisk != 1) {
      unsigned long long int *arg = va_arg(*a, unsigned long long int *);
      *arg = arg1;
    }
  } else if (param->length[0] == 'h') {
    unsigned int arg1 = (unsigned)s21_atoi(s, param);
    if (param->asterisk == 0) {
      unsigned short int *arg = va_arg(*a, unsigned short int *);
      *arg = (unsigned short int)arg1;
    }
  } else {
    unsigned int arg1 = (unsigned)s21_atoi(s, param);
    if (param->asterisk == 0) {
      unsigned int *arg = va_arg(*a, unsigned int *);
      *arg = arg1;
    }
  }
}

long double s21_atof(const char **str, params *param) {
  long double result = 0.0;
  long double result_right = 0.0;
  long double result_left = 0.0;
  float scale = 0.0;
  long double sign = 1.0;
  long double e_value = 0.0;

  const char *start_of_str = *str;
  param->flag_data_failed = 1;

  sign = set_sign(str, param);
  int i = 0; // позиция курсора?
  result_right = chr_to_dec(&i, str, param);
  e_value = e_check(str, &scale, param);

  if (param->width != -1 && param->flag_data_failed == 1) param->width--;

  if (**str == '.' && (param->width > 0 || param->width == -1)) {
    (*str)++;
    decrese_width(param);
    i = 0;
    result_left = chr_to_dec(&i, str, param);
    while (i > 0) {
      result_left /= 10.0;
      i--;
    }
  }
  result = result_right + result_left;
  if (scale == 0) e_value = e_check(str, &scale, param);
  if (scale != 0) {
    while (e_value > 0) {
      result *= scale;
      e_value--;
    }
  }
  if (param->flag_data_failed == 1) {
    *str = start_of_str;
    if ((s21_strncmp(*str, "inf", 3) == 0) ||
        (s21_strncmp(*str, "INF", 3) == 0) ||
        (s21_strncmp(*str, "Inf", 3) == 0) ||
        (s21_strncmp(*str, "inF", 3) == 0) ||
        (s21_strncmp(*str, "InF", 3) == 0))

    {
      result = INFINITY;
      param->flag_data_failed = 0;
      *str += 3;
    }
    if ((s21_strncmp(*str, "nan", 3) == 0) ||
        (s21_strncmp(*str, "NAN", 3) == 0) ||
        (s21_strncmp(*str, "NaN", 3) == 0) ||
        (s21_strncmp(*str, "Nan", 3) == 0) ||
        (s21_strncmp(*str, "naN", 3) == 0) ||
        (s21_strncmp(*str, "nAN", 3) == 0)) {
      result = NAN;
      param->flag_data_failed = 0;
      *str += 3;
    }
  } else
    result *= sign;
  param->width = -1;

  return result;
}

void type_decimal(const char **str, params *param, va_list *ap) {
  long double *arg_float_is_not_failed = calloc(1, sizeof(long double));
  *arg_float_is_not_failed = s21_atof(str, param);
  if (param->asterisk != 1) {
    if (param->flag_data_failed == 0) {
      if (param->length[0] == 'L') {
        *(va_arg(*ap, long double *)) = *arg_float_is_not_failed;
      } else if (param->length[0] == 'l') {
        *(va_arg(*ap, double *)) = (double)(*arg_float_is_not_failed);
      } else {
        *(va_arg(*ap, float *)) = (float)(*arg_float_is_not_failed);
      }
    }
  }

  free(arg_float_is_not_failed);
}

void type_int(const char **str, params *param, va_list *ap, int base) {
  long long int *arg_int_is_not_failed = calloc(1, sizeof(long long int));

  *arg_int_is_not_failed = hex_to_dex(str, base, param);

  if (param->asterisk != 1) {
    if (param->flag_data_failed == 0) {
      if ((param->length[0] == 'l') && (param->is_unsigned == 0) &&
          (param->length[1] != 'l')) {
        *(va_arg(*ap, long int *)) = (long int)*arg_int_is_not_failed;
      } else if ((param->length[0] == 'l') && (param->is_unsigned == 0) &&
                 (param->length[1] == 'l')) {
        *(va_arg(*ap, long long int *)) = (long long int)*arg_int_is_not_failed;
      } else if ((param->length[0] == 'h') && (param->is_unsigned == 0)) {
        *(va_arg(*ap, short int *)) = (short int)*arg_int_is_not_failed;
      } else if ((param->length[0] == '\0') && (param->is_unsigned == 0)) {
        *(va_arg(*ap, int *)) = (int)*arg_int_is_not_failed;
      } else if ((param->length[0] == 'l') && (param->is_unsigned == 1) &&
                 (param->length[1] != 'l')) {
        *(va_arg(*ap, long unsigned int *)) =
            (long unsigned int)*arg_int_is_not_failed;
      } else if ((param->length[0] == 'l') && (param->is_unsigned == 1) &&
                 (param->length[1] == 'l')) {
        *(va_arg(*ap, long long unsigned int *)) =
            (long long unsigned int)*arg_int_is_not_failed;
      } else if ((param->length[0] == 'h') && (param->is_unsigned == 1)) {
        *(va_arg(*ap, short unsigned int *)) =
            (short unsigned int)*arg_int_is_not_failed;
      } else if ((param->length[0] == '\0') && (param->is_unsigned == 1) &&
                 param->is_ptr == 1) {
        *(va_arg(*ap, void **)) = (void *)*arg_int_is_not_failed;
      } else if ((param->length[0] == '\0') && (param->is_unsigned == 1)) {
        *(va_arg(*ap, unsigned int *)) = (unsigned int)*arg_int_is_not_failed;
      }
    }
  }
  free(arg_int_is_not_failed);
}

void case_c(const char **str, va_list *ap, params *param) {
  if (*str && **str != '\0') {
    if (param->asterisk == 0) {
      char *arg_char = va_arg(*ap, char *);
      *arg_char = (unsigned char)**str;
    }
    (*str)++;
  } else {
    param->flag_data_failed = 1;
  }
}

long long int hex_to_dex(const char **str, int base, params *param) {
  long long int result = 0x0;
  param->flag_data_failed = 1;
  const char *start_str = *str;
  long long int sign = set_sign(str, param);
  if (base == 0) {
    if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X'))
      base = 16;
    else if (**str == '0')
      base = 8;
    else
      base = 10;
  }

  if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X') &&
      (base == 16)) {
    if (param->width > 1 || param->width == -1) {
      (*str)++;
      (*str)++;
      decrese_width(param);
      decrese_width(param);
      param->flag_data_failed = 0;
    }
  } else if (**str == '0' && (base == 8)) {
    if (param->width > 0 || param->width == -1) {
      (*str)++;

      decrese_width(param);
      param->flag_data_failed = 0;
    }
  }

  while (((**str >= 48 && **str <= 57) || (**str >= 65 && **str <= 70) ||
          (**str >= 97 && **str <= 102)) &&
         (param->width > 0 || param->width == -1)) {
    if (**str >= 48 && **str <= 55) {
      result = (**str - '0') + result * base;
      (*str)++;
      decrese_width(param);
    } else if ((**str >= 56 && **str <= 57) && (base != 8)) {
      result = (**str - '0') + result * base;
      (*str)++;
      decrese_width(param);
    } else if ((**str >= 65 && **str <= 70) && (base != 8) && (base != 10)) {
      result = (**str - 55) + result * base;
      (*str)++;
      decrese_width(param);
    } else if ((**str >= 97 && **str <= 102) && (base != 8) && (base != 10)) {
      result = (**str - 87) + result * base;
      (*str)++;
      decrese_width(param);
    }
    param->flag_data_failed = 0;
  }
  if (param->flag_data_failed == 1) *str = start_str;
  return result * sign;
}

void parser_sscanf(const char *format, va_list *a, int *count, const char **s,
                   const int *i, params *param, const char **start_s) {
  switch (format[*i]) {
    case 'c':
      while (**s == ' ' && **s != '\0' && *i != 1) {
        (*s)++;
      }

      case_c(s, a, param);
      if (param->flag_data_failed == 0 && param->asterisk == 0) param->result++;
      break;
    case 's':
      if (param->width == -1) param->width = 0;
      if (**s == '\0') {
        break;
      }
      skip_space(s);

      *count = counter(*s, param);

      case_s(*s, a, *count, param);

      if (param->flag_data_failed == 0 && param->asterisk == 0) {
        param->result++;
      }

      break;
    case 'u':
      skip_space(s);

      case_u(param, s, a);
      if (param->flag_data_failed == 0 && param->asterisk == 0) param->result++;
      break;
    case 'x':
    case 'X':
      skip_space(s);
      if (**s != '\0') {
        if (param->width == 0) param->width = -1;
        param->is_unsigned = 1;
        type_int(s, param, a, 16);
        if (param->flag_data_failed == 0 && param->asterisk == 0)
          param->result++;
      } else
        param->result = 4294967295;
      break;
    case 'p':
      skip_space(s);
      if (param->width == 0) param->width = -1;
      param->is_unsigned = 1;
      param->is_ptr = 1;
      type_int(s, param, a, 16);
      if (param->flag_data_failed == 0 && param->asterisk == 0) param->result++;
      break;
    case 'd':
      skip_space(s);

      case_d(param, s, a);
      if (param->flag_data_failed == 0 && param->asterisk == 0) param->result++;
      break;
    case 'i':
      skip_space(s);
      if (param->width == 0) param->width = -1;
      param->is_unsigned = 1;

      type_int(s, param, a, 0);
      if (param->flag_data_failed == 0 && param->asterisk == 0) param->result++;
      break;
    case 'n':
      if (param->asterisk == 0) *(va_arg(*a, int *)) = *s - *start_s;
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      skip_space(s);

      if (param->width == 0) param->width = -1;

      type_decimal(s, param, a);
      if (param->flag_data_failed == 0 && param->asterisk == 0) param->result++;
      break;
    case 'o':
      skip_space(s);
      if (param->width == 0) param->width = -1;
      param->is_unsigned = 1;
      type_int(s, param, a, 8);
      if (param->flag_data_failed == 0 && param->asterisk == 0) param->result++;
      break;
    default:
      break;
  }
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  params param = {0};
  const char *start_s = str;
  param.flag_data_failed = 0;
  param.is_unsigned = 0;
  param.result = 0;

  for (int i = 0; format[i] != '\0' && param.flag_data_failed == 0; i++) {
    param.width = 0;
    param.length[0] = '\0';
    param.asterisk = 0;
    param.is_ptr = 0;

    while (format[i] == *str && *str != '%') {
      i++;
      str++;
    }
    if (format[i] == '%') {
      i++;
      if (format[i] == '*') {
        param.asterisk = 1;
        i++;
      } else {
        param.asterisk = 0;
      }
      set_params(&param, &format, &i);
      int count = 0;
      parser_sscanf(format, &args, &count, &str, &i, &param, &start_s);
      str = str + count;
      count = 0;
    }
  }
  va_end(args);
  if (param.result == 0) param.result = 0;
  return param.result;
}

void skip_space(const char **s) {
  while ((**s == ' ' || **s == '\t' || **s == '\n')) {
    (*s)++;
  }
}
