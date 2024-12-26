#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>

void generate_random_filename(char *filename, size_t length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t charset_size = sizeof(charset) - 1;

    for (size_t i = 0; i < length; i++) {
        int key = rand() % charset_size;
        filename[i] = charset[key];
    }
    filename[length] = '\0';
}

void copy_file(const char *src, const char *dest) {
    FILE *source_file = fopen(src, "rb");
    if (!source_file) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest_file = fopen(dest, "wb");
    if (!dest_file) {
        fclose(source_file);
        perror("Failed to open destination file");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
}

int main() {
    unsigned char byte;
    int offset;
	int byte_num = 3;

	char filename[256] = "/tmp/";
	char random_filename[256];
	srand((unsigned)time(NULL));
	generate_random_filename(random_filename, 16);
	strcat(filename, random_filename);

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	
	copy_file("./bin/dummy", filename);
	chmod(filename, 0755);

	FILE *f = fopen(filename, "r+b");

	for (int i = 0; i < byte_num; i++) {
		printf("Enter the byte value (0-255): ");
		scanf("%hhu", &byte);
		printf("Enter the offset for the byte: ");
		scanf("%d", &offset);

		if (f == NULL) {
			perror("Error opening file");
			return EXIT_FAILURE;
		}

		if (fseek(f, offset, SEEK_SET) != 0) {
			perror("Error seeking to offset");
			fclose(f);
			return EXIT_FAILURE;
		}
		if (fwrite(&byte, sizeof(byte), 1, f) != 1) {
			perror("Error writing byte");
			fclose(f);
			return EXIT_FAILURE;
		}
	}

    fclose(f);

    int result = system(filename);

    return 0;
}
