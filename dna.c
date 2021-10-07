/*
dna.c
Renee Palmer
Student ID: 500998526
Assignment #2 - decodes a sequence of DNA
CCPS 393 Section BA0
Instructor: L. Hiraki
Purpose: Decodes a sequence of DNA and print the corresponding amino acids to standard output
*/
#include "dna.h"

int main (int argc, char *argv[]) {
// declaration
    FILE *dna; 
    int base, newBase; 
    int acidCount, baseCount, firstBase, secondBase, thirdBase;
// initializations
    firstBase = secondBase = thirdBase = acidCount = baseCount = 0; 
    char aminoAcid[4][4][4] = {
// T = 0, C = 1, A = 2, G = 3
        {
            {'F', 'F', 'L', 'L'},
            {'S', 'S', 'S', 'S'},
            {'Y', 'Y', '*', '*'},
            {'C', 'C', '*', 'W'} 
        },
        {
            {'L', 'L', 'L', 'L'},
            {'P', 'P', 'P', 'P'},
            {'H', 'H', 'Q', 'Q'},
            {'R', 'R', 'R', 'R'}
        },
        {
            {'I', 'I', 'I', 'M'},
            {'T', 'T', 'T', 'T'},
            {'N', 'N', 'K', 'K'},
            {'S', 'S', 'R', 'R'}
        },
        {
            {'V', 'V', 'V', 'V'},
            {'A', 'A', 'A', 'A'},
            {'D', 'D', 'E', 'E'},
            {'G', 'G', 'G', 'G'}
        }};
// check to make sure that there is correct number of command arguments (ex. file is included on command line)
    dna = fopen(argv[1], "r");
    if (argc != 2)
    {
        printf("Must enter file name\n");
        return 1;
    }
// check to see if file is empty 
    if (dna == NULL)
    {
        printf("File cannot be opened or file is empty\n");
        return 1;
    }
// loop to read characters one-at-a-time
    while ((base = getc(dna)) != EOF)
    {
// send character to check function to make sure character is base character
            newBase = check(&base, dna);
// conditional to check if character is a readable ASCII character (EOF check)
            if (newBase < 0)
            {
                break;
            }
// match base character to number in code function 
            firstBase = code(&newBase);
// increment when a base if read
            baseCount++;

            base = getc(dna);
            newBase = check(&base, dna);
            if (newBase < 0)
            {
                break;
            }
            secondBase = code(&newBase);
            baseCount++;

            base = getc(dna);
            newBase = check(&base, dna);
            if (newBase < 0)
            {
                break;
            }
            thirdBase = code(&newBase);
            baseCount++;

            printf("%c", aminoAcid[firstBase][secondBase][thirdBase]);
// increment when a acid is read
            acidCount++;
    }
// print bases and acids processed 
    printf("\n");
    printf("Total number bases processed: %d\n", baseCount);
    printf("Total number of amino acids decoded: %d\n", acidCount);
// close file
    fclose(dna);

    return 0;
}

