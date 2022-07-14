#include "monty.h"

/**
 * monty_nop - No function
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
 * monty_pchar - prints the top char in a stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
set_op_tok_error(pchar_error(line_number, "stack empty"));
return;
}
if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
{
set_op_tok_error(pchar_error(line_number, "value out of range"));
return;
}
printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - prints a string contained in stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
stack_t *temp = (*stack)->next;

while (temp && temp->n != 0 && (temp->n && temp->n <= 127))
{
printf("%c", temp->n);
temp = temp->next;
}
printf("\n");
(void)line_number;
}
