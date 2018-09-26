	/* Ahmad Hanjoura
	 * CMPT 360
	 * Lab 2
	 * shell.c
	 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

	/*ANSWER: The variable in the child and parent process
	 *before changing it is the initial value of 100. When
	 *changing it in each process, both correctly changed
	 *the variable to their respective values of 50 and 25.
	 */

int main(void)
{
	int x = 100;
	int rc = fork();

	if (rc < 0) {		// fork failed
		fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {	// child process
		printf("Value of x is %d before the child changes it\n", x);
		x = 50;
		printf("This is the child and he says x = %d\n", x);
	} else {			// parent process
		printf("Value of x is %d before the parent changes it\n", x);
		x = 25;
		printf("This is the parent and he says x = %d\n", x);
	}
	return 0;
}
