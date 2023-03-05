#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
// execvpe will need this implict declaration.
#define _GNU_SOURCE
#include <unistd.h>

int main(int argc, char* argv[], char* env[]) {
	pid_t id = fork();
	if (id < 0) {
		printf("fail to fork\n");
	} else if (id == 0) {
		printf("child process\n");
		/* execl case
		 * execl("/bin/ls", "/bin/ls", (char *) NULL);
		 */
		/* execle case
		 * execle("/bin/ls", "/bin/ls", (char *) NULL, env);
		 */
		/* execlp case
		 * execlp("/bin/ls", "/bin/ls", (char *) NULL);
		 */
		/* execv case
		 * char *args[] = {"/bin/ls", NULL};
		 * execv("/bin/ls", args);
		 */
		/*
		 * char * args[] = {"ls", NULL};
		 * execvp("ls", args);
		 */
		char *args[] = {"ls", NULL};
		execvpe("ls", args, env);
	} else {
		wait(NULL);
		printf("father process\n");
	}
	return 0;
}
