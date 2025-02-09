%%
[0-9]+         printf("Numbers: %s\n", yytext);
[a-zA-Z]+      printf("Word: %s\n", yytext);
.
%%
int yywrap(void)
{
    return 1;
}
int main(void){
    yylex();
    return 0;
}