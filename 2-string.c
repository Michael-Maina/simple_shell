#include "main.h"

/**
*_strncmp - compares two strings
*
*@s1: string parameter
*@s2: string parameter
*@n: number of bytes
*
*Return: difference between the strings
*/

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	for (; *s1 != '\0' && *s2 != '\0' && *s1 == *s2;)
	{
		s1++;
		s2++;
		i++;
		if (i == n)
			break;
	}
	return (*s1 - *s2);
}

/**
*_strdup - duplicates a string
*
*@str: string parameter
*
*Return: pointer to a duplicate of str
*/

char *_strdup(char *str)
{
	char *s;
	size_t i = 0, len = 0;

	len = _strlen(str);

	s = malloc(sizeof(char *) * (len + 1));

	if (s == NULL)
		return (NULL);

	while(i <= len)
	{
		s[i] = str[i];
		i++;
	}

	return (s);
}
