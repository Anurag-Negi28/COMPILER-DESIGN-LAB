// Write a program which takes input as the no. of productions and the productions
// It checks if the left recursion is there or not
// Then outputs the production eliminating left recursion
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTIONS 100
#define MAX_LENGTH 100

// Function to check and eliminate left recursion
void eliminateLeftRecursion(char nonTerminal, char productions[MAX_PRODUCTIONS][MAX_LENGTH], int prodCount)
{
    int i, hasLeftRecursion = 0;
    char alpha[MAX_PRODUCTIONS][MAX_LENGTH], beta[MAX_PRODUCTIONS][MAX_LENGTH];
    int alphaCount = 0, betaCount = 0;

    // Separate productions into alpha (left recursive) and beta (non-left recursive)
    for (i = 0; i < prodCount; i++)
    {
        if (productions[i][0] == nonTerminal)
        {
            hasLeftRecursion = 1;
            strcpy(alpha[alphaCount++], productions[i] + 1); // Skip the non-terminal
        }
        else
        {
            strcpy(beta[betaCount++], productions[i]);
        }
    }

    if (!hasLeftRecursion)
    {
        printf("No left recursion found for %c.\n", nonTerminal);
        return;
    }

    // Print the original productions
    printf("Original Productions for %c:\n", nonTerminal);
    for (i = 0; i < prodCount; i++)
    {
        printf("  %c -> %s\n", nonTerminal, productions[i]);
    }

    // Eliminate left recursion
    char newNonTerminal = nonTerminal + '\'';
    printf("\nEliminated Left Recursion for %c:\n", nonTerminal);
    for (i = 0; i < betaCount; i++)
    {
        printf("  %c -> %s%c\n", nonTerminal, beta[i], newNonTerminal);
    }
    for (i = 0; i < alphaCount; i++)
    {
        printf("  %c -> %s%c\n", newNonTerminal, alpha[i], newNonTerminal);
    }
    printf("  %c -> ε\n", newNonTerminal); // Add epsilon production
}

int main()
{
    int n, i, j;
    char nonTerminal;
    char productions[MAX_PRODUCTIONS][MAX_LENGTH];

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter production %d (e.g., A->Ab|c): ", i + 1);
        char input[MAX_LENGTH];
        scanf("%s", input);

        // Parse the input into non-terminal and productions
        nonTerminal = input[0];
        char *rhs = strchr(input, '>') + 1;
        char *token = strtok(rhs, "|");
        j = 0;
        while (token != NULL)
        {
            strcpy(productions[j++], token);
            token = strtok(NULL, "|");
        }

        // Eliminate left recursion for the current non-terminal
        eliminateLeftRecursion(nonTerminal, productions, j);
    }

    return 0;
}