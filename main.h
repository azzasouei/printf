#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @fn: The function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - Struct op
 *
 * @format: The format.
 * @fm_t: The function associated.
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *i,
va_list args, char buff[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list args, char buff[],
	int flags, int width, int precision, int size);
int print_string(va_list args, char buff[],
	int flags, int width, int precision, int size);
int print_per(va_list args, char buff[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list args, char buff[],
	int flags, int width, int precision, int size);
int print_bin(va_list args, char buff[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buff[],
	int flags, int width, int precision, int size);
int print_octal(va_list args, char buff[],
	int flags, int width, int precision, int size);
int print_hexa(va_list args, char buff[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buff[],
	int flags, int width, int precision, int size);

int print_hex(va_list args, char map_to[],
char buff[], int flags, char flags_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list args, char buff[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list args, char buff[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int flags(const char *format, int *i);
int width(const char *format, int *i, va_list args);
int precision(const char *format, int *i, va_list args);
int size(const char *format, int *i);

/*Function to print string in reverse*/
int print_rev(va_list args, char buff[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13(va_list args, char buff[],
	int flags, int width, int precision, int size);

/* width handler */
int write_char(char c, char buff[],
	int flags, int width, int precision, int size);
int write_num(int is_neg, int ind, char buff[],
	int flags, int width, int precision, int size);
int num(int ind, char buff[], int flags, int width, int precision,
	int len, char padd, char extra_c);
int pointer(char buff[], int ind, int len,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_neg, int ind,
char buff[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hex_code(char, char[], int);
int is_digit(char);

long int convert_size_numb(long int num, int size);
long int convert_size_unsignd(unsigned long int num, int size);

#endif /* MAIN_H */
