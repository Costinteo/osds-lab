#include <stdio.h>

typedef struct {
	char *name;
	unsigned int price;
} ingredient_t;

ingredient_t PRICE_LIST = {
	{"Lettuce", 1},
	{"Tomato", 2},
	{"Jalapeno", 5},
	{"Chicken", 10},
	{"Pork", 15},
	{"Beef", 25},
};

void order_sandwich() {
	unsigned int ingredient_num;

	puts("< How many ingredients would you like in your sandwich?");
	printf("> ");
	scanf("%u", &ingredient_num);
	puts("< Here is our price list:");
	for (int i = 0; i < sizeof(PRICE_LIST)/sizeof(*PRICE_LIST); i++) {
		printf("%d. %s [$%u]\n", i+1, PRICE_LIST[i].name, PRICE_LIST[i].price);
	}

	unsigned int total_pay = 0;
	unsigned int ingredient_idx;
	for (int i = 0; i < ingredient_num; i++) {
		while (1) {
			printf("[ingredient no. %u/%u] > ", i+1, ingredient_num);
			scanf("%u", &ingredient_idx);
			ingredient_idx--;
			if (ingredient_idx < 0 || ingredient_idx >= sizeof(PRICE_LIST)/sizeof(*PRICE_LIST)) {
				puts("< That's not a valid ingredient! Try again.");
				continue;
			}
			total_pay += PRICE_LIST[ingredient_idx].price
			break;
		}
	}

}

void option_menu() {
	char *options[] = {
		"Order Sandwich"
		"Check Order Number",
		"Tell the cashier Subway is better",
		"Convert money",
		"Exit",
	};

	for (int i = 0; i < sizeof(options)/sizeof(*options); i++) {
		printf("%d. %s\n", i+1, options[i]);
	}
}



int main() {
	int choice;


	puts("< Welcome to .hidden hacker sandwiches! How may I help you today?");
	puts("< Oh, just so you know, the order screen is broken, it won't update unless you press the 'Check Order' button.");
	puts("< Also, we only accept US dollars here.");

	while (1) {
		option_menu();
		printf("Choose option: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				order_sandwich();
				break;
			case 2:
				check_order();
				break;
			case 3:
				puts("< Uhhh.. Alright, anything else I can do for you?");
				break;
			case 4:
				convert();
				break;
			case 5:
				puts("< Happy hacking!");
				return 0;
			default:
				puts("No such choice!");
				break;
		}
	}
}


void menu() {

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
	return 0;
}
