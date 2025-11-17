#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL (void*)0

#define FLAG_MINUS (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_SPACE (1 << 2)

typedef struct {
    int flags;
    int width;
    int precision;
    int length;
    char specifier;
} FormatOptions;

#if UINTPTR_MAX == 0xFFFFFFFFFFFFFFFFUL // 64-битная платформа
typedef unsigned long s21_size_t;
#elif UINTPTR_MAX == 0xFFFFFFFFUL // 32-битная платформа
typedef unsigned int s21_size_t;
#endif
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);
void apply_format(char **buffer, va_list args, FormatOptions options);
void format_c(char **str, char c, FormatOptions options);
void format_d(char **str, long num, FormatOptions options);
//void format_f(char **str, double num, FormatOptions options);
void format_s(char **str, char *src, FormatOptions options);
void format_u(char **str, unsigned long int num, FormatOptions options);

char *double_to_str(double num);
char *int_to_str(long num);

//BONUS
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
#endif