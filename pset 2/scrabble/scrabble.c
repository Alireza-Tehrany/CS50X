#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(char word[]);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(char word[])
{
    // TODO: Compute and return score for string
    int len = strlen(word);
    int arrLen = sizeof characters / sizeof characters[0];
    int arrLen2 = sizeof POINTS / sizeof POINTS[0];
    int index = 0;
    int point_sum = 0;

    for (int m = 0; word[m] != '\0'; m++)
    {
        word[m] = tolower(word[m]);
    }

    for (int i = 0; i <= arrLen; i++)
    {
        for (int j = 0; word[j] != '\0'; j++)
        {
            if (word[j] == characters[i])
            {
                point_sum = point_sum + POINTS[i];
                break;
            }
        }
    }
    return point_sum;
}
