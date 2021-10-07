#include "dna.h"
int code(int *c){
int index;
// send index number according to character passed to function
        if(*c == 'T')
        {
            index = 0;
        }
        else if(*c == 'C')
        {
            index = 1;        
        }
        else if(*c == 'A')
        {
            index = 2;
        }
        else if(*c == 'G')
        {
            index = 3;
        }

        return index;
    }