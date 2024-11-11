#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX_COUNT 64
#define NOTE_SIZE 16

char NOTES[MAX_COUNT][NOTE_SIZE] = {};
int USED_COUNT = 0;

void menu() {
	puts("..::[.HIDDEN SMALL NOTES]::..");
	printf("Currently using: %d/%d notes\n\n", USED_COUNT, MAX_COUNT);
	char *options[] = {
		"Create Note",
		"Read Note",
		"Exit",
	};

	for (int i = 0; i < sizeof(options)/sizeof(*options); i++) {
		printf("%d. %s\n", i+1, options[i]);
	}
}

void notes_create() {
	int index;
	printf("Input the index for your secure note: ");
	scanf("%d", &index);
	getc(stdin);
	if (index >= MAX_COUNT) {
		return; // Invalid index
	}

	printf("Input your note: ");
	gets(NOTES[index]);

	USED_COUNT++;
}

void notes_read() {
	int index;
	printf("Input the index for your secure note: ");
	scanf("%d", &index);
	if (index >= MAX_COUNT) {
		return; // Invalid index
	}

	printf("NOTE[%d]: %s\n", index, NOTES[index]);
}

int main() {
	int choice;

	while (1) {
		menu();
		printf("Choose option: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				notes_create();
				break;
			case 2:
				notes_read();
				break;
			case 3:
				return 0;
			default:
				puts("No such choice!");
				break;
		}
	}
}
