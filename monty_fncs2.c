#include "monty.h"

/**
 * monty_add - adds the first 2 elements of stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Description: stores the sum to the second node int inthe list
 *and pops the stack
 * Return: none
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "add"));
return;
}

(*stack)->next->next->n += (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
 * monty_sub - subracts the first 2 elements of stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Description: stores the difference to the second node int inthe list
 *              and pops the stack
 * Return: none
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "sub"));
return;
}

(*stack)->next->next->n -= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
 * monty_div - divides the second val to the top value
 * @stack: poiter to a stack
 * @line_number: current working line in monty bytecode
 *
 * Description: stores the quotient to the second node of the stack
 * Return: none
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "div"));
return;
}

if ((*stack)->next->n == 0)
{
set_op_tok_error(div_error(line_number));
return;
}

(*stack)->next->next->n /= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
 * monty_mul - multiplies the first 2 elements of stack
 * @stack: pointer to a stack
 * @line_number: current working line of monty bytecode
 *
 * Description: stores the product to the second node int inthe list
 *              and pops the stack
 * Return: none
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "mul"));
return;
}

(*stack)->next->next->n *= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
 * monty_mod - divides the second val to the top value
 * @stack: poiter to a stack
 * @line_number: current working line in monty bytecode
 *
 * Description: stores the modulus result to the second node of the stack
 * Return: none
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "mod"));
return;
}

if ((*stack)->next->n == 0)
{
set_op_tok_error(div_error(line_number));
return;
}

(*stack)->next->next->n %= (*stack)->next->n;
monty_pop(stack, line_number);
}
