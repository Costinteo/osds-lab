#include <stdio.h>
#include <string.h>
char *SECRET = ".hidden";
int main() {
	long is_admin = 0;
	char password[8];
	scanf("%s", password);
	if (0 == strcmp(password, SECRET)) {
		is_admin = 0xDEADBEEF;
	}
	
	if (is_admin == 0xDEADBEEF) {
		puts("Access granted!");
	} else {
		puts("Access denied!");
    }
}
