#include "main.h"

/**
 * *_memcpy - copies memory area
 * @dest: destination string
 * @src: source string
 * @n: number of bytes
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

#include "main.h"

/**
 * *_memset - fills memory with a constant byte
 * @s: pointer to string s
 * @b: constant byte
 * @n: number of bytes of memory
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
