#include <stdio.h>
#include <string.h>

int main() {
    char line[200];
    printf("Enter a line:\n");
    fgets(line, sizeof(line), stdin);

    if (!strncmp(line, "//", 2))
        printf("Single-line comment\n");

    else if (!strncmp(line, "/*", 2) && strstr(line, "*/"))
        printf("Multi-line comment\n");

    else if (!strncmp(line, "/*", 2))
        printf("Incomplete multi-line comment\n");

    else
        printf("Not a comment\n");

    return 0;
}


