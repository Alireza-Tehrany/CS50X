#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter Height:");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int m = 1; m < height - i; m++)
        {
            printf(" ");
        }

        for (int z = 0; z <= i; z++)
        {
            printf("#");
        }

        printf("  ");

        for (int y = 0; y <= i; y++)
        {
            printf("#");
        }

        printf("\n");
    }
}