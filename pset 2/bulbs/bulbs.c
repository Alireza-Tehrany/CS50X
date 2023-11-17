#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string text = get_string("Text: ");
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int decimal = text[i];
        int m = 0;
        while (decimal > 0)
        {
            binary[m] = decimal % 2;
            decimal = decimal / 2;
            m++;
        }

        for (int n = BITS_IN_BYTE - 1; n >= 0; n--)
        {
            print_bulb(binary[n]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
