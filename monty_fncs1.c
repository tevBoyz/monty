#include "monty.h"

/**
 * monty_push - push a val into a stack
 * @stack: pointer to a stack
 * @line_number: current working line number of monty bytecode
 *
 * Return: none
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
stack_t *temp, *newnode;
int i;
newnode = malloc(sizeof(stack_t));
if (newnode == NULL)
{
set_op_tok_error(malloc_error());
return;
}
if (opcode_tok[1] == NULL)
{
set_op_tok_error(no_int_error(line_number));
return;
}
for (i = 0; opcode_tok[1][i]; i++)
{
if (opcode_tok[1][i] == '-' && i == 0)
continue;
if (opcode_tok[1][i] < '0' || opcode_tok[1][i] > '9')
{
set_op_tok_error(no_int_error(line_number));
return;
}
}
newnode->n = atoi(opcode_tok[1]);
if (check_mode(*stack) == STACK)
{
temp = (*stack)->next;
newnode->prev = *stack;
newnode->next = temp;
if (temp)
temp->prev = newnode;
(*stack)->next = newnode;
}
else
{
temp = *stack;
while (temp->next)
temp = temp->next;
newnode->prev = temp;
newnode->next = NULL;
temp->next = newnode;
}
}

/**
 * monty_pall - prints the vals in stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
stack_t *temp = (*stack)->next;

while (temp)
{
printf("%d\n", temp->n);
temp = temp->next;
}
(void)line_number;
}

/**
 * monty_pint - prints the top value of stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
set_op_tok_error(pint_error(line_number));
return;
}
printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - removes top value from stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp = NULL;
if ((*stack)->next == NULL)
{
set_op_tok_error(pop_error(line_number));
return;
}
temp = (*stack)->next->next;
free((*stack)->next);
if (temp)
temp->prev = *stack;
(*stack)->next = temp;
}

/**
 * monty_swap - Swaps top 2 elements of stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return:none
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "swap"));
return;
}

temp = (*stack)->next->next;
(*stack)->next->next = temp->next;
(*stack)->next->prev = temp;
if (temp->next)
temp->next->prev = (*stack)->next;
temp->next = (*stack)->next;
temp->prev = *stack;
(*stack)->next = temp;
}
