#include <stdio.h>
#include <stdlib.h>

int main() {
    char* contents = calloc(2, sizeof(char));
    if (contents == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Fill the contents with some characters
    for (int i = 0; i < 2; i++) {
        contents[i] = 'A' + i; // Fill with 'A' and 'B'
    }
    // Print the contents
    printf("Contents: %c %c\n", contents[0], contents[1]);

    // Free allocated memory
    free(contents);
    return 0;
}