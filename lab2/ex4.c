#include <stdio.h>

int main() {
	char buffer[256];
	printf("Buffer at %p\n", buffer);
	gets(buffer);
	return 0;
}
