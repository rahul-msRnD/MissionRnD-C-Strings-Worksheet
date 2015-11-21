/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<string.h>
char KthIndexFromEnd(char *str, int k) {
	if(!str || k<0 ) return '\0';
	int l = strlen(str);
	return str[l - k-1];
}