#include <stdio.h>
#include <sys/mman.h>

int main() {

	/* Open an executable file here */
	/* ... */

	/* Fill in the details here! */
	void *ptr = mmap(...);

	/* Copy the bytes here */
	/* ... */

	/* This monster casts ptr to a function pointer with no args and calls it. Basically jumps to your code. */
	(*(void(*)()) ptr)();
}
