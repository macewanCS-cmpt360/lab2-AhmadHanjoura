	/* Ahmad Hanjoura
	 * CMPT 360
	 * Lab 2
	 * shell.c
	 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int rc = fork();

	if (rc < 0) {		// fork failed
		fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {	// child process

		while (1) {   
			char *cmdline;
			char *token = NULL;
			int i, rc;
			char *args[10];

			cmdline = calloc(1, 1024);
			i = 0;

			printf("prompt> ");
			fgets(cmdline, 1024, stdin);

			token = strtok(cmdline, "\n ");
			while (token != NULL) {
				//printf("%s\n", token);
				args[i++] = strdup(token);
				token = strtok(NULL, "\n ");
			}
			args[i] = NULL;
			free(cmdline);

			execvp(args[0], args);
		}

	} else {		// parent process
		int rc_wait = wait(NULL);
	}

	return 0;
}
