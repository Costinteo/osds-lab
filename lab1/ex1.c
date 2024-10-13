#include <stdio.h>

char useful[] = "Where is this located?";

void bar(int n, char *p) {
	for (int i = 0; i < n; i++) {
		puts(useful);
	}
}

int main() {
	while (1) {}
}
