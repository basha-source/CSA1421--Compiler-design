#include <stdio.h>
#include <ctype.h>

int main() {
    char s[500]; int i=0;
    printf("Enter program:\n");
    fgets(s,500,stdin);

    while(s[i]){
        if(isspace(s[i])){ i++; continue; }

        if(s[i]=='/'&&s[i+1]=='/')
            while(s[i]&&s[i++]!='\n');

        else if(s[i]=='/'&&s[i+1]=='*'){
            i+=2;
            while(s[i]&&!(s[i]=='*'&&s[i+1]=='/')) i++;
            if(s[i]) i+=2;
        }
        else putchar(s[i++]);
    }
    return 0;
}

