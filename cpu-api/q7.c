#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
int main() {
	int pipefd[2];
	char buf;
	pipe(pipefd);
	pid_t id = fork();
	if (id == 0) {
		sleep(1);
		while (read(pipefd[0], &buf, 1) > 0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
	} else {
		pid_t s_id = fork();
		if (s_id == 0) {
			write(pipefd[1], "test", strlen("test"));
		} else {
			wait(NULL);
		}
	}
}
