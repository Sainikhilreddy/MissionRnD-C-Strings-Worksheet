/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int numtostr(int, char *);
void revstr(char *, int);

void number_to_str(float number, char *str,int afterdecimal){
	int n,l=0,i=0;  
	if (number < 0)
	{
		str[l++] = '-';
		number = -number;
	}
	n = (int)number;
	float f = number - n;
	i=numtostr(n, str + l);
	revstr(str + l,i);
	l += i;
	if (afterdecimal != 0)
	{
		str[l++] = '.';
		for (i = 1, n = 1; i <= afterdecimal; i++)
			n *= 10;
		f *= n; 
		n = (int)f;
		i = numtostr(n, str + l);
		revstr(str + l, i);
		l += i;
	}
	str[l] = '\0';

	
}
int numtostr(int n, char * str)
{
	int i = 0;
	printf("\n%d", n);
	while (n > 0)
	{
		str[i++] = n % 10+'0';
		n = n / 10;
	}
	return i;
}
void revstr(char *str,int l)
{
	int i, j, t;
	for (i = 0, j = l - 1; i < j; i++, j--)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
	}
}
