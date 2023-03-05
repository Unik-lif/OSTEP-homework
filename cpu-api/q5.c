#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 

int main() {
	pid_t id = fork();
	if (id < 0) {
		printf("fail to fork");
	} else if (id == 0) {
		wait(NULL); // on error, it will return -1.
		printf("child process\n");

	} else {
		pid_t id = waitpid(-1, NULL, 0);
		printf("id = %d\n", id);
		printf("parent process\n");
	}
	return 0;
}
