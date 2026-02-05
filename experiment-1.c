#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isOperator(char ch) {
    return strchr("+-*/=%<>", ch) != NULL;
}

void printFeedback(const char *type, const char *value) {
    printf("%s: %s\n", type, value);
}

void analyzeCode(const char *code) {
    int i = 0;

    for (i = 0; code[i] != '\0'; i++) {

        if (isspace(code[i])) continue;

        if (code[i]=='/' && code[i+1]=='/') {
            while (code[i] && code[i]!='\n') i++;
            continue;
        }

        if (code[i]=='/' && code[i+1]=='*') {
            while (code[i] &&
                  !(code[i]=='*' && code[i+1]=='/')) i++;
            if (code[i]) i++;
            continue;
        }

        if (isalpha(code[i]) || code[i]=='_') {
            char id[50];
            int j = 0;

            while ((isalnum(code[i]) || code[i]=='_') && j<49)
                id[j++] = code[i++];

            id[j] = '\0';
            printFeedback("Identifier", id);
            i--;
            continue;
        }

        if (isdigit(code[i])) {
            char num[50];
            int j = 0;

            while (isdigit(code[i]) && j<49)
                num[j++] = code[i++];

            num[j] = '\0';
            printFeedback("Constant", num);
            i--;
            continue;
        }

        if (isOperator(code[i])) {
            char op[2] = {code[i], '\0'};
            printFeedback("Operator", op);
        }
    }
}

int main() {
    char code[500];
    printf("Enter a statement:\n");
    fgets(code, sizeof(code), stdin);
    analyzeCode(code);
    return 0;
}

