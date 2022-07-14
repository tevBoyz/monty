#define _XOPEN_SOURCE 700
#include "monty.h"

int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t **, unsigned int);


/**
 * free_tokens - freesthe global opcode_tok array
 */
void free_tokens(void)
{
size_t i = 0;
if (opcode_tok == NULL)
return;

for (; opcode_tok[i]; i++)
free(opcode_tok[i]);

free(opcode_tok);
}

/**
 * token_arr_len - returns length of the opcode_tok
 *
 * Return: int val for length
 */
unsigned int token_arr_len(void)
{
unsigned int len = 0;

while (opcode_tok[len])
len++;

return (len);
}

/**
 * is_empty_line - checks if line from get line is empty
 * @line: poiter to the line
 * @delims: a sting of delimiter chars
 *
 * Return: 1 if line contans only delimiters, 0 - otherwise
 */
int is_empty_line(char *line, char *delims)
{
int i, j;

for (i = 0; line[i]; i++)
{
for (j = 0; delims[j]; j++)
{
if (line[i] == delims[j])
break;
}
if (delims[j] == '\0')
return (0);
}
return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
instruction_t op_funcs[] = {
{"push", monty_push},
{"pall", monty_pall},
{"pint", monty_pint},
{"pop", monty_pop},
{"swap", monty_swap},
{"add", monty_add},
{"nop", monty_nop},
{"sub", monty_sub},
{"div", monty_div},
{"mul", monty_mul},
{"mod", monty_mod},
{"pchar", monty_pchar},
{"pstr", monty_pstr},
{"rotl", monty_rotl},
{"rotr", monty_rotr},
{"stack", monty_stack},
{"queue", monty_queue},
{NULL, NULL}};
int i;

for (i = 0; op_funcs[i].opcode; i++)
{
if (strcmp(opcode, op_funcs[i].opcode) == 0)
return (op_funcs[i].f);
}
return (NULL);
}

/**
 * run_monty - main function to execute monty bytecodes
 * @script_fd: File decriptor for an open Montybytecode
 *
 * Return: exit code
 */
int run_monty(FILE *script_fd)
{
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0, exit_status = EXIT_SUCCESS;
unsigned int line_number = 0, prev_tok_len = 0;
void (*op_func)(stack_t **, unsigned int);

if (init_stack(&stack) == EXIT_FAILURE)
return (EXIT_FAILURE);

while (getline(&line, &len, script_fd) != -1)
{
line_number++;
opcode_tok = strtow(line, DELIMS);
if (opcode_tok == NULL)
{
if (is_empty_line(line, DELIMS))
continue;
free_stack(&stack);
return (malloc_error());
}
else if (opcode_tok[0][0] == '#')
{
free_tokens();
continue;
}
op_func = get_op_func(opcode_tok[0]);
if (op_func == NULL)
{
free_stack(&stack);
exit_status = unknown_op_error(opcode_tok[0], line_number);
free_tokens();
break;
}
prev_tok_len = token_arr_len();
op_func(&stack, line_number);
if (token_arr_len() != prev_tok_len)
{
if (opcode_tok && opcode_tok[prev_tok_len])
exit_status = atoi(opcode_tok[prev_tok_len]);
else
exit_status = EXIT_FAILURE;
free_tokens();
break;
}
free_tokens();
}
free_stack(&stack);

if (line && *line == 0)
{
free(line);
return (malloc_error());
}
free(line);
return (exit_status);
}
