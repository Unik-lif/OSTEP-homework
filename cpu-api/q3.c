#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t id = fork();
	if (id < 0) {
		printf("fail to fork");
	} else if (id == 0) {
		printf("hello");
	} else {
		sleep(1);
		printf("goodbye");
	}
	return 0;
}
