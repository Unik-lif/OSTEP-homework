#include <stdio.h>
// fork function
#include <sys/types.h>
#include <unistd.h>
int main() {
	int x = 10;
	pid_t id = fork();
	if (id < 0) {
		printf("fail to fork\n");
	} else if (id == 0) {
		x = 20;
		printf("x value = %d\n", x);
	} else {
		x = 30;
		printf("x value = %d\n", x);
	}
}
