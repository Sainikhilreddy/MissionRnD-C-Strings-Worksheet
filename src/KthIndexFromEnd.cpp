/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>

char KthIndexFromEnd(char *str, int K) {
	int l; 
	
	if (str != NULL&&K >= 0 )
	{
		for (l = 0; str[l]; l++);
		if (K < l)
			return str[l - 1 - K];
		else
			return '\0';
	}
	else
		return '\0';
}