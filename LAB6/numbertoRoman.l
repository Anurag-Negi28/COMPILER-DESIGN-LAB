/* Write a flex program to convert a Decimal number into Roman Number */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToRoman(int num, char *result) {
    struct roman {
        int value;
        const char *numeral;
    } roman[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"},
        {0, NULL} // Sentinel value
    };

    result[0] = '\0'; // Initialize result as an empty string

    for (int i = 0; roman[i].value > 0; i++) {
        while (num >= roman[i].value) {
            strcat(result, roman[i].numeral);
            num -= roman[i].value;
        }
    }
}
%}

%%
[0-9]+ {
    int num = atoi(yytext);
    char result[100];
    decimalToRoman(num, result);
    printf("%s\n", result);
}
.|\n;
%%
int yywrap() {
    return 1;
}
int main(void) {
    yylex();
    return 0;
}