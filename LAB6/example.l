%{
#include <stdio.h>
#include <string.h>

int lengs[100] = {0}; // Initialize the array to zero
%}
%%
[a-zA-Z]+ {
    lengs[yyleng]++;
    if(yyleng == 1) printf("<%s>", yytext);
}
. | \n;
%%
int yywrap()
{
    int i;
    printf("Length  No. words\n");
    for(i = 0; i < 100; i++) {
        if(lengs[i] > 0)
            printf("%5d%10d\n", i, lengs[i]);
    }
    return 1;
}
int main(void){
    yylex();
    return 0;
}