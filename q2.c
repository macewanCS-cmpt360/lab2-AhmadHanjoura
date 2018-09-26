	/* Ahmad Hanjoura
	 * CMPT 360
	 * Lab 2
	 * shell.c
	 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

	/*ANSWER:
	 * Yes they can both access the value returned by open()
	 * Both the parent and child output to the file, one
	 * after the other. The order is not guarenteed,
	 * as it states in the textbook, either the child or
	 * the parent might run at that point.
	 */

int main(void)
{
	int file = open("q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int rc = fork();

	if (rc < 0) {		// fork failed
		fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {	// child process
		printf("The file descriptor in the child is %d\n", file);
		char *child_string = "I am child\n";

		write(file, child_string, strlen(child_string));
		close(file);
	} else {		// parent process
		printf("The file descriptor in the parent is %d\n", file);
		char *parent_string = "I am parent\n";

		write(file, parent_string, strlen(parent_string));
		close(file);
	}
	return 0;
}
