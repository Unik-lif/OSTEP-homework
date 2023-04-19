#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if (argc != 3) exit(0);

	// number of megabytes of memory it will use.
	long memory_size = (long) atoi(argv[1]) * 1024 * 1024;
	// time for touching each part once.
	int time = atoi(argv[2]);
	int temp;

	char* array = (char*) malloc(memory_size);
	memset(array, 0, memory_size);
	clock_t begin = clock();
	double time_spent;
	while (1) {
		time_spent = (double) (clock() - begin) / CLOCKS_PER_SEC;
		if (time_spent >= time) break;	
		for (int i = 0; i < memory_size; i++) {
			array[i] += 1;
		}
	}

	return 0;
}
