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

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	char *s;
	char *p[10] = {NULL};
	int i1, i2=0, j1,j2, l;
	if (str1 == NULL || str2 == NULL)
		return NULL;
	for (i1 = 0; str1[i1]; i1++)
	{
			l = 0;
			j1 = 0;
			while (str2[j1] )
			{
				if (str1[i1] == str2[j1])
				{
					i1++;
					j1++;
					l++;
				}
				else if (l>1 && str1[i1] == ' '&&str2[j1] == ' ')
				{
					s = (char *)malloc(10);
					for (j2 = 0, i1 -= l; j2<l; j2++, i1++)
						s[j2] = str1[i1];
					s[j2] = '\0';
					l = 0;
					p[i2++] = s;
					break;

				}
				else if (l >= 1)
				{
					i1 -= l;
					l = 0;
					j1++;
				}
				j1++;
			}
			if (l > 1 &&  (str2[j2] == '\0'&&str2[i1] == ' '))
			{
				s = (char *)malloc(10);
				for (j2 = 0, i1 -= l; j2<l; j2++, i1++)
					s[j2] = str1[i1];
				s[j2] = '\0';
				p[i2] = s;
			}
	}
	return p;
}