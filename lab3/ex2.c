#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char souldream[256] = {};
char ephemereal[] = "/bin/sh";

void dream_msg(char *msg) {
	int color = 31;
	for (int i = 0; i < 5; i++) {
		printf("\x1b[%dm%s\n", color + i, msg);
	}
	printf("\x1b[0m");
}

void __attribute__((no_caller_saved_registers)) scramble_dream(char *dream) {
	int mult;
	for (int i = 0; dream[i]; i++) {
		mult = 1;
		for (int j = 0 ; j < i + 1; j++) {
			mult *= i;
		}
		dream[i] = dream[i] * 42 * mult % 128;
	}
}

void nightmare() {
	char bad_nightmare[64];
	puts("Sometimes, even dreams can become nightmares.");
	memcpy(bad_nightmare, souldream, sizeof(souldream));

	puts("The Glade of Dreams is shattered...");
}

void dream() {
	puts("What is your dream?");
	scanf("%255s", souldream);
}

void deep_sleep() {
	system("head -n 3 /dev/urandom");
}

int main() {
	puts("Dreams of bytes... Nightmares of shells...");
	puts("This is where bits and pieces of programs return.");
	puts("Can you find them all?");
	dream();
	scramble_dream(ephemereal);
	nightmare();
	deep_sleep();
}
