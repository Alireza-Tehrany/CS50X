#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width; row++)
        {
            if (image[row][column].rgbtBlue == 0 && image[row][column].rgbtGreen == 0 && image[row][column].rgbtRed == 0)
            {
                image[row][column].rgbtBlue = 165;
                image[row][column].rgbtGreen = 245;
                image[row][column].rgbtRed = 255;
            }
        }
    }
}
