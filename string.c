#include "main.h"

/**
 * *_strcpy - copies the string pointed to by src including null byte(\0)
 *            to the buffer pointed to by dest
 * @src: source of string to be copied
 * @dest: destination of string to be copied
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int a, b = 0;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[b] = src[a];
		b++;
	}
	dest[b] = '\0';

	return (dest);
}

/**
 * _strcat - appends the src string to the dest string
 *           overwriting the terminating null byte at the end
 *           of dest, then adds a terminating null byte
 * @src: first string
 * @dest: second string
 *
 * Return: returns a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int len_dest = 0;
	int len_src = 0;

	for (; dest[len_dest] != '\0'; len_dest++)
		;

	for (; src[len_src] != '\0' ;)
		dest[len_dest++] = src[len_src++];

	dest[len_dest] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if identical
 *         <0 if first char in s1's ASCII value less than that of s2
 *         >0 if first charin s2's ASCII value greater than that of s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}

	return (s1[i] - s2[i]);
}
