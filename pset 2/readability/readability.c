#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int compute_characters(string text);
int compute_words(string text);
int compute_sentences(string text);

int main(void)
{

    string text = get_string("text: ");
    int letters = compute_characters(text);
    int words = compute_words(text);
    int sentences = compute_sentences(text);
    float L = 100 * (letters / (float) words);
    float S = 100 * (sentences / (float) words);
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    printf("%i\n", index);
    printf("%i\n", letters);
    printf("%i\n", words);
    printf("%i\n", sentences);
    printf("%f\n", L);
    printf("%f\n", S);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int compute_characters(string text)
{
    int letters = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters = letters + 1;
        }
    }
    return letters;
}

int compute_words(string text)
{
    int words = 1;
    int len = strlen(text);
    for (int p = 0; p < len; p++)
    {
        if (isblank(text[p]) != 0)
        {
            words = words + 1;
        }
    }
    return words;
}

int compute_sentences(string text)
{
    int sentences = 0;
    int dots[] = {'.', '?', '!'};
    int len = strlen(text);
    int arrLen = sizeof dots / sizeof dots[0];

    for (int z = 0; z <= arrLen; z++)
    {
        for (int j = 0; text[j] != '\0'; j++)
        {
            if (text[j] == dots[z])
            {
                sentences = sentences + 1;
            }
        }
    }
    return sentences;
}