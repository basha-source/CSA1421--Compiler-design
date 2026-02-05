#include <stdio.h>
#include <ctype.h>

int main() {
    char id[50];
    int i = 0, valid = 1;

    printf("Enter identifier: ");
    scanf("%s", id);

    if (!(isalpha(id[0]) || id[0] == '_')) valid = 0;

    for (i = 1; id[i] && valid; i++)
        if (!(isalnum(id[i]) || id[i] == '_'))
            valid = 0;

    if (valid) printf("Valid identifier\n");
    else printf("Invalid identifier\n");

    return 0;
}

