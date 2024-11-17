#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INGREDIENTS 8
#define MAX_INGREDIENT_NAME_LEN 8

typedef struct __attribute__((__packed__)) {
	char name[MAX_INGREDIENT_NAME_LEN];
	unsigned char price;
} ingredient_t;

typedef struct {
	ingredient_t ingredients[MAX_INGREDIENTS];
	char *codename;
	void (*taste_function)(void);
} sandwich_t;

ingredient_t PRICE_LIST[256] = {
	{"Tomato", 2},
	{"Onion", 5},
	{"Chicken", 12},
	{"Pork", 15},
	{"Beef", 25},
};


unsigned int INGREDIENTS_COUNT = 5;

void backup_orders(char *backups_filename) {
	char cmd[128];
	snprintf(cmd, 127, "/bin/cp ./orders.txt %s", backups_filename);
	system(cmd);
}

void good_taste() {
	puts("Yum! Good!");
}

sandwich_t *order_sandwich() {
	unsigned int ingredient_num;
	sandwich_t *sandwich = malloc(sizeof(sandwich_t));
	sandwich->taste_function = good_taste;

	while (1) {
		puts("< How many ingredients would you like in your sandwich?");
		printf("You can have at most %d.\n> ", MAX_INGREDIENTS);
		scanf("%u", &ingredient_num);
		if (ingredient_num > MAX_INGREDIENTS) {
			printf("< That's more than %d!\n", MAX_INGREDIENTS);
			continue;
		}
		puts("< Here is our price list:");
		for (int i = 0; i < INGREDIENTS_COUNT; i++) {
			printf("%d. %s [$%u]\n", i+1, PRICE_LIST[i].name, PRICE_LIST[i].price);
		}
		break;
	}

	unsigned int ingredient_idx;
	for (int i = 0; i <= ingredient_num; i++) {
		while (1) {
			printf("[ingredient no. %u/%u] > ", i, ingredient_num);
			scanf("%u", &ingredient_idx);
			ingredient_idx--;
			if (ingredient_idx < 0 || ingredient_idx >= INGREDIENTS_COUNT) {
				puts("< That's not a valid ingredient! Try again.");
				continue;
			}
			memcpy(sandwich->ingredients[i].name, PRICE_LIST[ingredient_idx].name, MAX_INGREDIENT_NAME_LEN);
			sandwich->ingredients[i].price = PRICE_LIST[ingredient_idx].price;
			break;
		}
	}
	puts("< How should we name it?\n");
	sandwich->codename = malloc(32);
	scanf("%31s", sandwich->codename);
	return sandwich;
}

void add_custom() {
	if (INGREDIENTS_COUNT + 1 > 255) {
		puts("< Sorry! Too many custom ingredients!\n");
		return;
	}

	puts("< You want something custom? Sure, what's the name?\n");
	printf("> ");
	scanf("%15s", PRICE_LIST[INGREDIENTS_COUNT].name);

	puts("< And the price?");
	printf("> ");
	scanf("%hhu", &PRICE_LIST[INGREDIENTS_COUNT].price);
	INGREDIENTS_COUNT++;
}

void eat(sandwich_t *sandwich) {
	sandwich->taste_function();
}

void option_menu() {
	char *options[] = {
		"Order sandwich",
		"Add custom ingredient",
		"Eat",
		"Tell the cashier Subway is better",
		"Exit",
	};

	for (int i = 0; i < sizeof(options)/sizeof(*options); i++) {
		printf("%d. %s\n", i+1, options[i]);
	}
}

int main() {
	int choice;
	sandwich_t *sandwich = NULL;


	puts("< Welcome to .hidden hacker sandwiches! How may I help you today?");

	while (1) {
		option_menu();
		printf("\nChoose option: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				sandwich = order_sandwich();
				break;
			case 2:
				add_custom();
				break;
			case 3:
				if (sandwich) eat(sandwich);
				else puts("< Dude... You haven't ordered anything!\n");
				break;
			case 4:
				puts("< Uhhh.. Alright, anything else I can do for you?\n");
				break;
			default:
				puts("No such choice!");
				break;
		}
	}
}

