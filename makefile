dna : dna.o dna.h check.o code.o 
	gcc -o dna dna.o check.o code.o 
dna.o: dna.c dna.h check.c code.c 
	gcc -c dna.c check.c code.c 
check.o: check.c dna.h
	gcc -c check.c
code.o: code.c dna.h 
	gcc -c code.c 
clean: 
	-rm *.o dna