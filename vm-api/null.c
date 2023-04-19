#include <stdio.h>

int main() {
	int a = 5;
	int* p = &a;
	p = NULL;
	printf("%d", *p);
}
