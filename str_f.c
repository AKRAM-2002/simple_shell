#include "shell.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * _strdup - strdup
 * @s: string
 * Return: pointer
*/
char *_strdup(const char *s)
{
	int len = 0;
	char *ret;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--s;
	return (ret);
}
/**
 * _strcpy - strcpy
 * @dest: dest
 * @src: src
 * Return: pointer
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strcmp - strcmp function
 * @s1: str 1
 * @s2: str 2
 * Return: result of comparison
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strlen - strlen
 * @s: string
 * Return: int
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}
/**
 * _strcat - strcat
 * @dest: dest
 * @src: src
 * Return: pointer to string
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
