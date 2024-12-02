#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>

typedef struct {
	char name[64];
	char time[64];
	char reason[64];
	int id;
} appointment_t;

typedef struct node_s {
	appointment_t data;
	struct node_s *prev;
	struct node_s *next;
} node_t;

int main();

char MSG_HEADER[] = "YOUR APPOINTMENT IS IN OUR SYSTEM! HERE IT IS:";
node_t **DB_HEAD = NULL;

void backdoor() {
	char *argv[] = {"/bin/sh", 0};
	printf("Here's your appointment:\n");
	execv(argv[0], argv);
}

void add_appointment(node_t *it, char *name, char *time, char *reason, int id) {
	it->next = malloc(sizeof(node_t));
	it->next->prev = it;
	it = it->next;
	strcpy(it->data.name, name);
	strcpy(it->data.time, time);
	strcpy(it->data.reason, reason);
	it->data.id = id;
}

void init() {
	DB_HEAD = malloc(sizeof(node_t *));
	*DB_HEAD = malloc(sizeof(node_t));
	add_appointment(*DB_HEAD, "Koyossu", "16:00 TUE", "stubbed toe", 0x1);
	add_appointment((*DB_HEAD)->next, "Lev", "13:00 THU", "PTSD", 0x12);
	add_appointment((*DB_HEAD)->next->next, "Honesty", "10:00 FRI", "SARS-COV2.5", 0x420);
	add_appointment((*DB_HEAD)->next->next->next, "Pinebel", "13:37 MON", "PWN overdose", 0x1337);
}

void interact() {
	node_t *it = *DB_HEAD;
	char *msg = MSG_HEADER;
	unsigned int actions = 2;
	char cmd[16];
	while (actions > 0) {
		printf("> ");
		read(0, cmd, 256);
		if (!strncmp("NEXT", cmd, 16)) {
			it = it->next;
		} else if (!strncmp("PREV", cmd, 16)) {
			it = it->prev;
		} else if (!strncmp("PRINT", cmd, 16)) {
			puts(msg);
			printf("NAME: %s\nTIME: %s\n REASON: %s\n", it->data.name, it->data.time, it->data.reason);
		} else {
			printf("Unknown command: %s\n", cmd);
			return;
		}
		actions--;
	}
}

int main() {
	int is_admin = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	init();
	puts("AVAILABLE COMMANDS:");
	puts("NEXT");
	puts("PREV");
	puts("PRINT");
	interact();
	if (is_admin == 0x1337) {
		backdoor();
	}
	return 0;
}
