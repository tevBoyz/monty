#include "monty.h"

/**
 * usage_error - usage error
 *
 * Return: (EXIT_FAILURE) always
 */
int usage_error(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
 * malloc_error - malloc error
 *
 * Return: (EXIT_FAILURE) always
 */
int malloc_error(void)
{
fprintf(stderr, "ERROR: malloc failed\n");
return (EXIT_FAILURE);
}

/**
 * f_open_error - file opening error
 * @filename: name of file failed to open
 *
 * Return: (EXIT_FAILURE) always
 */
int f_open_error(char *filename)
{
fprintf(stderr, "ERROR: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}

/**
 * unknown_op_error - unknown instruction error
 * @opcode: opcode at which error ocurred
 * @line_number: monty line number in bytecode
 *
 * Return: (EXIT_FAILURE) always
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
return (EXIT_FAILURE);
}


/**
 * no_int_error - invalid monty push error
 * @line_number: line number in monty bytecode
 *
 * Return: (EXIT_FAILURE) always
 */
int no_int_error(unsigned int line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}

