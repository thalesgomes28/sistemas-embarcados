C_DEFS = -Wall -g -c
L_DEFS = -lm
CONFIG = -DTIPO_FLOAT

all:
	gcc ${C_DEFS} ${CONFIG} lib_vector.c
	gcc ${C_DEFS} ${CONFIG} principal.c
	gcc lib_vector.o principal.o -o teste ${L_DEFS}
clean:
	rm *.o
	
