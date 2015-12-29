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
	while (*str1 && *str2) 
	{
		if (*str1 != *str2) 
			return false;
		str1++;
		str2++;
	}
	return true;
}


int noOfWords(char *str){

	int i = 0, c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			c += 1;
		i++;
	}
	if (c == i)
		return 0;
	return c + 1;
}

void copy(char *src, char *dest)
{
	int i = 0;
	for (i; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

char ** commonWords(char *str1, char *str2) {

	if (str1 == 0 || str2 == 0)
		return NULL;
	char *word;
	char **words2;
	int n1, n2;
	n1 = noOfWords(str1);
	n2 = noOfWords(str2);
	if (n1 == 0 || n2 == 0)
		return NULL;
	word = (char*)malloc(31 * sizeof(char));
	words2 = (char**)malloc(n1* sizeof(char*));
	int i, j = 0, k = 0;
	int commonWordsCount = 0;
	for (i = 0; i < n1; i++)
		words2[i] = (char*)malloc(31 * sizeof(char));
	for (i = 0, j = 0; str1[i] != '\0' && j<n1; i++)
	{
		if (str1[i] != ' ')
		{
			word[k] = str1[i];
			k++;
		}
		else if (str1[i] == ' ')
		{
			word[k] = '\0';
			k = 0;
			char* str;
			str = strstr(str2, word);
			if (strcmpr(str, word))
			{
				copy(word, words2[j]);
				j++;
				commonWordsCount++;
			}
		}

	}
	if (commonWordsCount > 0)
		return words2;
	else
		return NULL;
}

