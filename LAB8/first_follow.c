#include <malloc.h>
#include <stdio.h>
#include <string.h>

char **productions;
int fvar;

int findPos(char NonTer)
{
    int i = 0;
    while (productions[i][0] != NonTer)
        i++;
    return i;
}
char *findGenerating(char Ter)
{
    int i = 0;
    while (productions[i][0] != Ter)
        i++;
    return productions[i];
}
char findFirst(char *prod)
{
    int i, j = 0;
    for (i = 3; i < strlen(prod); i++)
    {
        if (prod[i] >= 97 && prod[i] <= 122 || prod[i] == ')' || prod[i] == '(' || prod[i] == ',')
        {
            printf(" %c ", prod[i]);

            while (prod[i] != '/' && prod[i] != '\0')
                i++;
            return prod[i]; // Return the terminal character
        }
        else if (prod[i] >= 65 && prod[i] <= 90)
        {
            printf("  %c", findFirst(productions[findPos(prod[i])]));
            return findFirst(productions[findPos(prod[i])]); // Return the result of recursive call
        }
        else if (prod[i] == '#')
        {
            printf("  #");
            return '#'; // Return '#' for epsilon
        }
        else
            continue;
    }
    return '\0'; // Return null character if no valid return condition is met
}

void findFollow(char GeneratingSymbol, int n)
{
    int i, j;
    static int visited[256] = {0}; // To avoid infinite recursion

    if (visited[GeneratingSymbol]) // If already visited, return
        return;

    visited[GeneratingSymbol] = 1;

    if (GeneratingSymbol == 'S') // Start symbol gets '$'
        printf(" $ ");

    for (j = 0; j < n; j++)
    {
        for (i = 3; i < strlen(productions[j]); i++)
        {
            if (GeneratingSymbol == productions[j][i])
            {
                if (productions[j][i + 1] >= 97 && productions[j][i + 1] <= 122 || productions[j][i + 1] == ')' || productions[j][i + 1] == '(' || productions[j][i + 1] == ',')
                {
                    printf(" %c ", productions[j][i + 1]);
                }
                else if (productions[j][i + 1] >= 65 && productions[j][i + 1] <= 90)
                {
                    findFirst(findGenerating(productions[j][i + 1]));
                }
                else if (i + 1 == strlen(productions[j])) // End of production
                {
                    findFollow(productions[j][0], n); // Add FOLLOW of LHS
                }
            }
        }
    }

    visited[GeneratingSymbol] = 0; // Reset visited for other calls
}
int main()
{
    int j, i, n, k, tempInd, flag = 0;
    printf("Enter the number of productions\n");
    scanf("%d\n", &n);
    productions = (char **)malloc(sizeof(char *) * n);
    for (i = 0; i < n; i++)
        productions[i] = (char *)malloc(sizeof(char) * 20);

    char **productionsDup = (char **)malloc(sizeof(char *) * n);
    for (i = 0; i < n; i++)
        productionsDup[i] = (char *)malloc(sizeof(char) * 20);

    for (i = 0; i < n; i++)
    {
        gets(productions[i]);
        productionsDup[i] = productions[i];
    }

    // First Computation
    for (i = 0; i < n; i++)
    {
        printf("\nFIRST(%c)={  ", productions[i][0]);
        char ans = findFirst(productions[i]);
        printf("}\n");
    }

    for (fvar = 0; fvar < n; fvar++)
    {
        printf("\nFOLLOW(%c)={", productions[fvar][0]);
        findFollow(productions[fvar][0], n);
        printf("}\n");
    }
    printf("\nThe End");
}