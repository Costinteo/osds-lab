#include <stdio.h>
#include <stdlib.h>

char souldream[128] = {};
char ephemereal[] = "/bin/sh";

char *strncpy(char *dest, const char *src, size_t n) {
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	return dest;
}

void dream_msg(char *msg) {
	int color = 31;
	for (int i = 0; i < 5; i++) {
		printf("\x1b[%dm%s\n", color, msg);
	}
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
	strncpy(bad_nightmare, souldream, sizeof(souldream));

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
	nightmare();
	scramble_dream(ephemereal);
	deep_sleep();
}
