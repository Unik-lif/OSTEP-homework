#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>
#include <sched.h>

int main(int argc, char* argv[]) {
	if (argc != 2) exit(1);
	int times = atoi(argv[1]);
	
	struct timeval start_time;
	struct timeval end_time;
	
	// create two pipes.
	int pipefd[2];
	int pipefd_copy[2];
	char wbuf = 'M';
	char rbuf;
	char wwbuf = 'N';
	char rrbuf;
	pipe(pipefd);
	pipe(pipefd_copy);

	// set the CPU to be 0.
	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET(0, &set);

	// use fork to get two processes.
	pid_t id = fork();
	if (id > 0) {
		int pid = getpid();
		sched_setaffinity(pid, sizeof(set), &set);
		gettimeofday(&start_time, NULL);
		for (int i = 0; i < times; i++) {
			write(pipefd[1], &wbuf, 1);
			read(pipefd_copy[0], &rbuf, 1);
		}
		wait(NULL);
		gettimeofday(&end_time, NULL);
		printf("context switch average time: %lf\n", ((end_time.tv_sec - start_time.tv_sec) * 1000 + end_time.tv_usec - start_time.tv_usec) * 1.0 / times);
	} else {
		int pid = getpid();
		sched_setaffinity(pid, sizeof(set), &set);
		for (int i = 0; i < times; i++) {
			read(pipefd[0], &rrbuf, 1);
			write(pipefd_copy[1], &wwbuf, 1);
		}

	}

	return 0;
}
