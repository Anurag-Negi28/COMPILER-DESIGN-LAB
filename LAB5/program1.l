%{
#include <stdio.h>
%}

%%
monday|tuesday|wednesday|thursday|friday|saturday|sunday { printf("<%s is a day.>", yytext); }
%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}