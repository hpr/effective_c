all: e1 e2

e1: e1.c
	gcc -std=c17 -o e1 e1.c

e2: e2.c
	gcc -std=c17 -o e2 -DDMALLOC e2.c -ldmalloc
