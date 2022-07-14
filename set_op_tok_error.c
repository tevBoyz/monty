#include "monty.h"

/**
 * set_op_toks_error - sets last element of opcode tokens as errors
 * @error_code: integer as opcode_tok
 *
 * Return: none
 */
void set_op_tok_error(int error_code)
{
int toks_len = 0, i = 0;
char *exit_str = NULL, **new_toks = NULL;

toks_len = token_arr_len();
new_toks = malloc(sizeof(char *) * (toks_len + 2));
if (!opcode_tok)
{
malloc_error();
return;
}
while (i < toks_len)
{
new_toks[i] = opcode_tok[i];
i++;
}
exit_str = get_int(error_code);
if (!exit_str)
{
free(new_toks);
malloc_error();
return;
}
new_toks[i++] = exit_str;
new_toks[i] = NULL;
free(opcode_tok);
opcode_tok = new_toks;
}
