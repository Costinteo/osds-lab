#include <stdio.h>

typedef struct booking {
	char *airline_name;
	char *name;
} booking_t;

booking_t bookings[] = {
	{"Royal PWN Airlines", "Pinebel"},
	{"Royal PWN Airlines", "Zenbassi"},
	{".hidden express", "MettleSphee"},
	{".hidden express", "0xC0FFEE"},
	{".hidden express", "Honesty"},
	{"Tech Wizz", "Lev"},
	{"Return Address", "Terry"}
};

int is_booked(char *airline_name, char *name) {
	booking_t booking_details = {airline_name, name};
	int n = sizeof(bookings) / sizeof(booking_t);
	int i, j = 0;
	for (i = 0; i < n; i++) {
		booking_t *p = &bookings[i];
		for (j = 0; p->airline_name[j] != 0 && airline_name[j] != 0; j++) {
			if (p->airline_name[j] != airline_name[j]) break;
		}
		if (p->airline_name[j] == 0 && airline_name[j] == 0) return 1;
	}
	return 0;
}

int check_booking() {
	char airlines[4][64] = {"Royal PWN Airlines", ".hidden express", "Tech Wizz", "Return Address"};
	char name[64];
	puts("Select an airline:");
	unsigned int index = 0;
	for (int i = 0; i < 4; i++) {
		printf("%d. %s\n", i, airlines[i]);
	}
	scanf("%u", &index);
	if (index > 3) {
		puts("Invalid airline index");
		return 0;
	}

	puts("Please input your name to check your booking:");
	scanf("%s", name);

	return is_booked(airlines[index], name);
}

int main() {
	puts("Welcome to the .hidden Flying Experience! Do you want to check your booking?");
	check_booking();
}
