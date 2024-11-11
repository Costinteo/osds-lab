#include <stdio.h>

char *intro = "It began with the forging of the Great Exploits. Three were given to the Academics, immortal, wisest and fairest of all. Seven to the Vuln Researchers, great pwners and craftsmen of the binary halls. And nine, nine exploits were gifted to Agencies, APTs which above all else desire power. For within these exploits were bound the techniques and bugs to pwn any program. But they were all of them deceived, for another exploit was made. Deep in the basement of Eastern Europe, beyond the firewalls, a black hat hacker planted a master backdoor, and hosted a C2 server for it in which she poured her AWS credits, her last ransom and her will to hack the world.";

int __attribute__((no_caller_saved_registers)) power(int x, int e) {
	int p = 1;
	for (int i = 0; i < e - 1; i++) {
		p *= x;
	}
	return x;
}

int main() {
	char name[32];
	puts(intro);
	puts("What was her name?");
	gets(name);
}
