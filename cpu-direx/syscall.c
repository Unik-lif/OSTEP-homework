#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	struct timeval start_time;
	struct timeval end_time;
	struct timezone start_tz;
	struct timezone end_tz;
	char *b;
	int fd = open("test", O_WRONLY|O_CREAT|O_SYNC);
	if (argc != 2) exit(1);
	gettimeofday(&start_time, &start_tz);
	for (int i = 0; i < atoi(argv[1]); i++) {
		read(fd, b, 0);
	}
	gettimeofday(&end_time, &end_tz);
	printf("average time: %lf\n", ((end_time.tv_sec - start_time.tv_sec) * 1000 + end_time.tv_usec - start_time.tv_usec) * 1.0 / atoi(argv[1]));
	return 0;	
}
