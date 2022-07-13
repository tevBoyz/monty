#include "monty.h"

/**
 * monty_rotl - rotate the top of stack to bottom
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
stack_t *top, *bottom;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
bottom = (stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;

top->next->prev = *stack;
(*stack)->next = top->next;
bottom->next = top;
top->next = NULL;
top->prev = bottom;

(void)line_number;
}

/**
 * monty_rotr - rotate the bottom of stack to top
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
stack_t *top, *bottom;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
bottom = (stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;

bottom->prev->next = NULL;
(*stack)->next = bottom;
bottom->pre = *stack;
bottom->next = top;
top->prev = bottom;

(void)line_number;
}

/**
 * monty_stack - chage a queue to a stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
(*stack)->n = STACK;
(void)line_number;
}

/**
 * monty_queue - change a stack to a queue
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Return: none
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
(*stack)->n = QUEUE;
(void)line_number;
}


