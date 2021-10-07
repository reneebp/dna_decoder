#include "dna.h"
int check(int *c, FILE* dna){
	int check = 0;
// check to see if character is alphabetic
	while (check == isalpha(*c))
	{
// if character is not alphabetic move one to next character
		*c = getc(dna);
		if (*c < 0)
		{
			return *c;
        }
	}
//check to see if character is a DNA base    
    while (*c != 'T' && *c != 't' && *c != 'C' && *c != 'c' && *c != 'A' && *c != 'a' && *c != 'G' && *c != 'g')
    {
        *c = getc(dna);
    }
// check to see if character is lowercase 
	if (check != islower(*c))
	{
		*c = toupper(*c);
	}

	return *c;
}
