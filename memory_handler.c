#include "main.h"

/**
 * bfree - frees a pointer and NULLs the address
 *
 * @ptr: address of the pointer to free
 *
 * Return: 1 if frees, otherwise 0
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}


/**
 * *memset_ - fills memory with a constant byte
 *
 * @s: the pointer to the memory area
 *
 * @b: the byte to fill *s with
 *
 * @n: the amount of bytes to be filled
 *
 * Return: (s) a pointer to the memory area s
 */

char *memset_(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 *
 * @pp: string of strings
 *
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * realloc_ - reallocates a block of memory
 *
 * @ptr: pointer to previous malloc'ated block
 *
 * @old_size: byte size of previous block
 *
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nemeen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
