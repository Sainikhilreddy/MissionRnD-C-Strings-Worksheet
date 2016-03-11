/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h> 

void rev(char *, int);

void str_words_in_rev(char *input, int len){
	int p,i;
	rev(input, len);
	for (i = 0,p=0; i < len; i++)
	{
		if (input[i] != ' ')
			p++;
		else
		{
			rev(input+i-p, p);
			p = 0;
		}

	}
	if (p>0)
		rev(input+i-p, p);
	
}
void rev(char *s, int len)
{
	int i, j,t;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}