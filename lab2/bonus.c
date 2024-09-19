#include <stdio.h>

char *msg = "The quieter you become, the more you are able to hear.";

int dothidden() {
	msg = "True hackers see beyond what they are told... You won!";
	return 0;
}

int win() {
	puts(msg);
	return 0;
}

int main() {
	char buf[30];
	scanf("%s", buf);
	return 0;
}
