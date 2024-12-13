#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX_COUNT 64

typedef struct note {
	char title[16];
	char content[48];
} note_t;

typedef struct config {
	void (*printer)(note_t *);
	char save_filename[56];
} config_t;

note_t *NOTES[MAX_COUNT] = {};
int USED_COUNT = 0;

config_t *CONFIG = NULL;

void menu() {
	puts("\n..::[.HIDDEN NOTES v2.0]::..");
	printf("Currently using: %d/%d notes\n\n", USED_COUNT, MAX_COUNT);
	char *options[] = {
		"Create Note",
		"Read Note",
		"Save Notes",
		"Configure",
		"Reset Config",
		"Changelog",
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
	if (index >= MAX_COUNT || index < 0) {
		puts("[!] Invalid index!");
		return;
	}

	if (NOTES[index] != NULL) {
		puts("[!] Note slot is occupied!");
		return;
	}

	note_t *note = malloc(sizeof(note_t));

	printf("Input your title: ");
	fgets(note->title, sizeof(note->title), stdin);

	printf("Input your note: ");
	fgets(note->content, sizeof(note->content), stdin);

	NOTES[index] = note;
	USED_COUNT++;
}

void notes_read() {
	if (CONFIG == NULL) {
		puts("[!] Config not found! Please configure printer.");
		return;
	}

	int index;
	printf("Input the index for your secure note: ");
	scanf("%d", &index);
	getc(stdin);
	if (index >= MAX_COUNT || index < 0) {
		puts("[!] Invalid index!");
		return;
	}

	if (NOTES[index] == NULL) {
		puts("[!] Note slot is empty!");
		return;
	}

	CONFIG->printer(NOTES[index]);
}

void notes_save() {
	if (CONFIG == NULL) {
		puts("[!] Config not found! Please configure save_filename.");
		return;
	}

	system("mkdir /tmp/dothidden_notes");
	char filepath[512];
	sprintf(filepath, "/tmp/dothidden_notes/%s", CONFIG->save_filename);
	FILE *f = fopen(filepath, "w");
	for (int i = 0; i < MAX_COUNT; i++) {
		if (NOTES[i] == NULL) continue;
		fputs(NOTES[i]->title, f);
		fputs(NOTES[i]->content, f);
		fputs("", f);
	}
	fclose(f);
}

void notes_printer(note_t *note) {
	puts("\n-----------------------");
	printf("Title: %s\n", note->title);
	printf("Content: %s\n", note->content);
	puts("-----------------------\n");
}

void configure() {
	CONFIG = malloc(sizeof(config_t));

	printf("Enter filename for save: ");
	fgets(CONFIG->save_filename, sizeof(CONFIG->save_filename), stdin);
	CONFIG->printer = notes_printer;
}

void reset_config() {
	free(CONFIG);
}


void changelog() {
	puts("");
	puts("______________________________________________________");
	puts("]:======[.HIDDEN NOTES v2.0 RELEASE CHANGELOG]======:[");
	puts("]:[== Fixed index validation;                    ==]:[");
	puts("]:[== Optimized memory usage by using the heap;  ==]:[");
	puts("]:[== Enhanced note structure;                   ==]:[");
	puts("]:[== Added configuration options;               ==]:[");
	puts("]:[== Deleted all fun things;                    ==]:[");
	puts("]:==================================================:[\n");
}

int main() {
	int choice;

	while (1) {
		menu();
		printf("Choose option: ");
		scanf("%d", &choice);
		getc(stdin);
		switch (choice) {
			case 1:
				notes_create();
				break;
			case 2:
				notes_read();
				break;
			case 3:
				notes_save();
				break;
			case 4:
				configure();
				break;
			case 5:
				reset_config();
				break;
			case 6:
				changelog();
				break;
			case 7:
				return 0;
			default:
				puts("No such choice!");
				break;
		}
	}
}
