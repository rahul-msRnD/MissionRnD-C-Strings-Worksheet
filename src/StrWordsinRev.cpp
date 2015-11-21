/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void reverseString(char *str, int l, int h)
{
	int s = l;
	int e = h;
	while (s<e)
	{
		swap(str + s, str + e);
		s++;
		e--;
	}
}


void str_words_in_rev(char *input, int len){
	int i;
	reverseString(input, 0, strlen(input) - 1);
	int l = 0, h = l;
	for (i = 0; i<strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			reverseString(input, l, h - 1);
			l = h + 1;
			h++;
		}
		else
			h++;
	}
	reverseString(input, l, h - 1);
}
