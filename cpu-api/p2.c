#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
	pid_t id = fork();
	if (id < 0) {
		printf("fail to fork\n");
	} else if (id == 0) {
		printf("child process\n");
		int fd = open("q2_test", O_RDWR);
		char test[] = "hello world!";
		write(fd, test, 20);	
	} else {
		printf("parent process\n");
		int fd = open("q2_test", O_RDWR);
		char test[] = "hallo morlD!";
		write(fd, test, 20);
	}
	return 0;
}
