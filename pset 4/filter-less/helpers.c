#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int mainblue, mainred, maingreen;
    float grayout;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            mainred = image[i][j].rgbtRed;
            mainblue = image[i][j].rgbtBlue;
            maingreen = image[i][j].rgbtGreen;

            grayout = round((mainred + mainblue + maingreen) / 3.0);

            image[i][j].rgbtRed = grayout;
            image[i][j].rgbtBlue = grayout;
            image[i][j].rgbtGreen = grayout;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalBlue, originalRed, originalGreen;
    int sepiaBlue, sepiaRed, sepiaGreen;

    for (int i = 0; i <= width; i++)
    {
        for (int j = 0; j <= height; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalBlue = image[i][j].rgbtBlue;
            originalGreen = image[i][j].rgbtGreen;

            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE row[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            row[j] = image[i][j];
        }
        for (int k = 0; k < width; k++)
        {
            image[i][k].rgbtRed = row[width - k - 1].rgbtRed;
            image[i][k].rgbtGreen = row[width - k - 1].rgbtGreen;
            image[i][k].rgbtBlue = row[width - k - 1].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            float sumred = 0;
            float sumblue = 0;
            float sumgreen = 0;

            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    if (!(i + m < 0 || i + m >= height || j + n < 0 || j + n >= width))
                    {
                        sumred += copy[i + m][j + n].rgbtRed;
                        sumblue += copy[i + m][j + n].rgbtBlue;
                        sumgreen += copy[i + m][j + n].rgbtGreen;
                        counter++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            image[i][j].rgbtRed = (int) round(sumred / counter);
            image[i][j].rgbtGreen = (int) round(sumgreen / counter);
            image[i][j].rgbtBlue = (int) round(sumblue / counter);
        }
    }
}
