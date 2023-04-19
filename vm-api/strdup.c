#include <string.h>
#include <stdio.h>

int main() {
	char s[] = "hallo";
	char* t = strdup(s);
	printf("%s t position: %p s position: %p\n", t, t, s);
	return 0;
}
