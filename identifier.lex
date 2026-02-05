%{
#include<stdio.h>
%}

%%
^[a-zA-Z0-9]+$ {
printf(" it is an identifeier");
}
.+ {
printf("its not an iddentifier");
}

%%
int yywrap(){}
int main()
{ 
printf("enter the identifier");
yylex();
return 0;

}
