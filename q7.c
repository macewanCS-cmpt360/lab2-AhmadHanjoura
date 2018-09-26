	/* Ahmad Hanjoura
	 * CMPT 360
	 * Lab 2
	 * q7.c
	 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

	/*ANSWER:
	 * The print satement did not print to stdout
	 */

int main(void)
{
	int rc = fork();

	if (rc < 0) {		// fork failed
		fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {	// child process
		close(STDOUT_FILENO);
		printf("This comes after the close()");
	} else {		// parent process

	}
	return 0;
}
