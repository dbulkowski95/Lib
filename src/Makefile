CFLAGS= -lcriterion -lm -Wall -Wextra -Wpedantic -Wcast-align -Winit-self 		\
	-Wmissing-include-dirs -Wredundant-decls -Wshadow -Wstrict-overflow=5 		\
	-Wundef -Wwrite-strings -Wpointer-arith -Wmissing-declarations 				\
	-Wuninitialized -Wold-style-definition -Wstrict-prototypes 					\
	-Wmissing-prototypes -Wswitch-default -Wbad-function-cast -Wnested-externs 	\
	-Wconversion -Wunreachable-code
	
build:
	gcc bitset.c -O3 $(CFLAGS)
clean:
	rm -f *.out *o *h.gch