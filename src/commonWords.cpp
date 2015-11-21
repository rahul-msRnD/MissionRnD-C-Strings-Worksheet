/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define SIZE 31

bool strcmpr(char *str1, char *str2)
{
	if (!str1 || !str2) return false;
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return false;
		}
		str1++;
		str2++;
	}
	return true;
}
char ** commonWords(char *str1, char *str2) 
{
	if (!str1 || !str2) return NULL;
	char *str, temp[10][10];
	int i = 0, j, k = 0, p = 0;
	char **r = (char**)malloc(31 * sizeof(char*));
	for (i = 0; i < 31; i++)
		r[i] = (char*)malloc(31 * sizeof(char));
	i = 0;
	if (strlen(str1) > strlen(str2))
	{
		while (str2[i] != '\0')
		{
			if (str2[i] != ' ')
			{
				j = 0;
				while (str2[i] != ' ' && str2[i] != '\0')
				{
					temp[p][j] = str2[i];
					j++;
					i++;
				}
				temp[p][j] = '\0';
				str = strstr(str1, temp[p]);
				if (strcmpr(str, temp[p]))
					r[k++] = temp[p++];
			}
			i++;
		}
	}
	if (k == 0) return NULL;
	return r;
}