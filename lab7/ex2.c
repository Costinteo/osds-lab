#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char FLIPPED = 0;
int SKIP_SLEEP = 0;

typedef unsigned long long int addr_t;

void intro_sleep(int sec) {
	if (!SKIP_SLEEP) sleep(sec);
}

void intro() {
	puts("INITIALIZING...\n");
	intro_sleep(1);
	puts(" [PROJECT] : 0XD-871337-B0");
	intro_sleep(1);
	puts("[CODENAME] : FLIPHAMMER");
	intro_sleep(1);
	puts("  [STATUS] : READY");
	intro_sleep(1);
	puts("--------------------------\n\n");
}

void menu() {
	char *options[] = {
		"FLIP",
		"EXIT",
	};

	for (int i = 0; i < sizeof(options)/sizeof(*options); i++) {
		printf("<%d> %s\n", i+1, options[i]);
	}
}


int flip_bit(addr_t address, unsigned int bitnum)
{
	if(bitnum > 7)
	{
		return -1;
	}
	if(FLIPPED != 0)
	{
		return -2;
	}
	char mask = (1 << bitnum);
	char val;
	FILE *f = fopen("/proc/self/mem", "r+");
	fseek(f, address, SEEK_SET);
	fread(&val, 1, 1, f);
	val ^= mask;

	fseek(f, address, SEEK_SET);
	fwrite(&val, 1, 1, f);

	fflush(f);
	fclose(f);

	FLIPPED = 1;
	return 0;
}

void shell() {
	system("/bin/ha");
}

int main(int argc, char *argv[]) {
	addr_t target;
	unsigned int bitnum;
	int ret;
	if (argc > 1) SKIP_SLEEP = 1;
	intro();
	while (1) {
		menu();
		int choice;
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("TARGET : ");
				scanf("%llx", &target);
				putc('\n', stdin);
				printf("BIT : ");
				scanf("%u", &bitnum);
				putc('\n', stdin);
				if ((ret = flip_bit(target, bitnum)) < 0) {
					printf("FLIPPING FAILED [%d]\n", ret);
				} else puts("FLIP SUCCESSFUL");
				break;
			case 2:
				exit(0);
				break;
			default:
				puts("UNKNOWN OPTION");
				break;
		}
	}
}
