#include <stdio.h>
#include <stdlib.h>

int main() {
	int* a = (int *) malloc(sizeof(int) * 100);
	a[0] = 4;
	free(a);
	printf("%d\n", a[0]);
	return 0;
}
