#include "monty.h"

/**
 * pop_error - pop error
 * @line_number: line number of monty byte code
 *
 * Return: (EXIT_FAILURE)always
 */
int pop_error(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pint_error - pint error
 * @line_number: line number of monty byte code
 *
 * Return: (EXIT_FAILURE)always
 */
int pint_error(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pint an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
 * short_stack_error -print monty math operation error
 * @line_number: line number of monty byte code
 * @op: operation
 *
 * Return: (EXIT_FAILURE)always
 */
int short_stack_error(unsigned int line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
return (EXIT_FAILURE);
}

/**
 * div_error - division error
 * @line_number: line number of monty byte code
 *
 * Return: (EXIT_FAILURE)always
 */
int div_error(unsigned int line_number)
{
fprintf(stderr, "L%u: division by zero", line_number);
return (EXIT_FAILURE);
}

/**
 * pchar_error - character related errors
 * @line_number: line number of monty byte code
 * @message: corresponding message
 *
 * Return: (EXIT_FAILURE)always
 */
int pchar_error(unsigned int line_number, char *message)
{
fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
return (EXIT_FAILURE);
}
