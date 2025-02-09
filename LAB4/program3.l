%{
    #include<stdio.h>
    int space_count=0;
    int tab_count=0;
%}
%%
" "             {space_count++;}
"\t"            {tab_count++;}
.               {/* Ignor other characters*/}
%%
int main()
{
    yylex();
    printf("Number of spaces: %d\n", space_count);
    printf("Number of tabs: %d\n", tab_count);
    return 0;
}
int yywrap()
{
    return 1;
}