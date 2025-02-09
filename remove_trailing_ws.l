%%
[ \t]+$ ;
[ \t]+ printf(" ");

%%
int yywrap() {
    return 1; /* Indicates no more input */
}
