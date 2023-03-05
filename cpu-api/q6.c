#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
	pid_t id = fork();
	if (id == 0) {
		close(STDOUT_FILENO);
		printf("hello\n");
	} else {
		wait(NULL);
		printf("goodbye\n");
	}
	return 0;
}
