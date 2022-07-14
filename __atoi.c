#include "monty.h"

unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
	       char *buff, int buff_size);

/**
 * get_int - get char pointer to new string container
 * @num: number to convert to string
 *
 * Return: char pointer
 */
char *get_int(int num)
{
unsigned int temp;
int length = 0;
long num_l = 0;
char *ret;

temp = _abs(num);
length = get_numbase_len(temp, 10);

if (num < 0 || num_l < 0)
length++;
ret = malloc(length + 1);
if (!ret)
return (NULL);

fill_numbase_buff(temp, 10, ret, length);
if (num < 0 || num_l < 0)
ret[0] = '-';

return (ret);
}

/**
 * _abs - returns absolute value of an integer
 * @i: interger to work on
 *
 * Return: unsigned int value
 */
unsigned int _abs(int i)
{
if (i < 0)
return (-(unsigned int)i);
return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed
 * @num: number to get length of
 * @base: base of the integer
 *
 * Return: length of the integer
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
int len = 1;

while (num > base - 1)
{
len++;
num /= base;
}
return (len);
}

/**
 * fill_numbase_buff - fill the buffer with correct nums upto base 36
 * @num: number to conver to string
 * @base: base of the number
 * @buff: buffer to fill with result
 * @buff_size: size of buffer in bytes
 *
 * Return: none
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
	       char *buff, int buff_size)
{
int rem, i = buff_size - 1;
buff[buff_size] = '\0';

while (i >= 0)
{
rem = num % base;
if (rem > 9)
buff[i] = rem + 87;
else
buff[i] = rem + '0';
num /= base;
i--;
}
}
