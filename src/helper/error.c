#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "error.h"

/**
 * Aborts program execution and prints a message on stderr.
 * The message works like printf.
 */
void failure(char* msg, ...) {
	va_list args;
	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);
	exit(1);
}

/**
 * Prints a warning message on stderr.
 * The message works like printf.
 */
void warning(char* msg, ...) {
	va_list args;
	va_start(args, msg);
	printf("WARNING: ");
	vfprintf(stderr, msg, args);
	va_end(args);
}
