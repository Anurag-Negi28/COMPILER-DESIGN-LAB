%{
#include <stdio.h>
#include <stdlib.h>
int k;
%}
%%
-?[0-9]+ {
    k = atoi(yytext); 
    printf("<%d>", k % 7 == 0 ? k + 3 : k + 1);
}
-?[0-9\.]+ ECHO;
[A-Za-z][A-Za-z0-9]+ printf("<%s>", yytext);
%%
int yywrap() {
    return 1;
}
int main(void){
    yylex();
    return 0;
}