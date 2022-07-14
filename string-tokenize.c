#include "monty.h"

int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - takes a string and separate the words in it
 * @str: compound string
 * @delims: limiters to use to separate the words
 *
 * Return: array of words
 */
char **strtow(char *str, char *delims)
{
char **words = NULL;
int wc, wordlen, n, i = 0;

if (str == NULL || !*str)
return (NULL);
wc = get_word_count(str, delims);

if (wc == 0)
return (NULL);
words = malloc((wc + 1) * sizeof(char *));
if (words == NULL)
return (NULL);

while (i < wc)
{
wordlen = get_word_length(str, delims);
if (is_delim(*str, delims))
str = get_next_word(str, delims);
words[i] = malloc((wordlen + 1) * sizeof(char));
if (words[i] == NULL)
{
while (i >= 0)
{
i--;
free(words[i]);
}
free(words);
return (NULL);
}
n = 0;
while (n < wordlen)
{
words[i][n] = *(str + n);
n++;
}
words[i][n] = '\0';
str = get_next_word(str, delims);
i++;
}
words[i] = NULL;
return (words);
}

/**
 * is_delim - checks if a char is a delimiter
 * @ch: char
 * @delims: array of delimeters
 *
 * Return: 1 is a delim 0 is not
 */
int is_delim(char ch, char *delims)
{
int i = 0;

while (delims[i])
{
if (delims[i] == ch)
return (1);
i++;
}
return (0);
}

/**
 * get_word_length - gets the lenght of the word
 * @str: string to get word length from
 * @delims: delimiters to use
 *
 * Return: word length
 */
int get_word_length(char *str, char *delims)
{
int wlen = 0, pending = 1, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
wlen++;
if (wlen > 0 && is_delim(str[i], delims))
break;
i++;
}
return (wlen);
}

/**
 * get_word_count - gets the word count in astring
 * @str: string
 * @delims: delimiters to separate the string
 *
 * Return: word count
 */
int get_word_count(char *str, char *delims)
{
int wc = 0, pending = 1, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
{
pending  = 0;
wc++;
}
i++;
}
return (wc);
}

/**
 * get_next_word - gets the next word in a string
 * @str: string to get word from
 * @delims: delimeter to separate words in string
 *
 * Return: poiter to word
 */
char *get_next_word(char *str, char *delims)
{
int pending = 0;
int i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
break;
i++;
}
return (str + i);
}
