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
