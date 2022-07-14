#include "monty.h"

/**
 * free_stack - Frees a stack from memory
 * @stack: pointer to a stack
 *
 * Return: none
 */
void free_stack(stack_t **stack)
{
stack_t *temp = *stack;

while (*stack)
{
temp = (*stack)->next;
free(*stack);
*stack = temp;
}
}

/**
 * init_stack - initialize a stack with starting stack and
 * ending queue nodes
 * @stack: pointer to an new stack
 *
 * Return: exit code
 */
int init_stack(stack_t **stack)
{
stack_t *s;

s = malloc(sizeof(stack_t));
if (s == NULL)
return (malloc_error());

s->n = STACK;
s->prev = NULL;
s->next = NULL;

*stack = s;

return (EXIT_SUCCESS);
}

/**
 * check_mode - check a list is a stack or queue
 * @stack: pointer to a stack
 *
 * Return: 0 if it is a stack
 * 1 if queue
 * 2 otherwise
 */
int check_mode(stack_t *stack)
{
if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (2);
}
