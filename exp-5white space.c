#include <stdio.h>

int main() {
    int ch, spaces = 0, newlines = 0;

    printf("Enter text (Ctrl+Z + Enter to stop):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t')
            spaces++;
        if (ch == '\n')
            newlines++;
    }

    printf("Whitespaces: %d\n", spaces);
    printf("Newlines: %d\n", newlines);

    return 0;
}

