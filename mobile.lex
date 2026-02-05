%{
%}

%%
[6-9][0-9]{9} {
    printf("The given number is valid\n");
}
.+ {
    printf("The given number is invalid\n");
}


%%

int yywrap(void) {}

int main() {
    printf("Enter the phone number: ");
    yylex();
}
