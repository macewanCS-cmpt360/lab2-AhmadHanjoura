
all: q1 q2 q3 q7 shell


shell: shell.c
	gcc -o shell shell.c

q1: q1.c
	gcc -o q1 q1.c

q2: q2.c
	gcc -o q2 q2.c

q3: q3.c
	gcc -o q3 q3.c

q7: q7.c
	gcc -o q7 q7.c

clean:
	rm *.o