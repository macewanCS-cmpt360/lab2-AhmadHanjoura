#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

	/*ANSWER:
	 * There is no way to ensure 100% that the
	 * child will print first, but by slowing down the
	 * parent it is more likely that the child will
	 * print first.
	 */

int main(void)
{
	int rc = fork();

	if (rc < 0) {		// fork failed
		fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {	// child process
		printf("Hello\n");
	} else {		// parent process
		//pleaseLetTheChildPrintFirst(NULL)?
		sleep(5);
		printf("Goodbye\n");
	}
	return 0;
}
