#include <stdio.h>
#include <stdlib.h>

char message[] = "Control is an illusion.";

void print_msg(char *msg) {
	printf("-==[ \x1b[31m%s\x1b[0m ]==-\n", msg);
}

void advertisment(int num, char *target) {
	printf("Looks like you have to endure %d ads. Good luck, %s.\n", num, target); 
	for (int i = 0; i < num; i++) {
		puts("Person completes OSDS Labs in 5 minutes with this one trick!");
		puts("Professors hate him!!");
		puts("----> Click here to find out his secret!!! <----");
	}
}

int main() {
	char name[256];
	puts("What's your name?");
	scanf("%255s", name);
	puts("Oh, ads incoming. Hope you have uBlock on...");
	advertisment(rand() % 10, name);
	return 0;
}
