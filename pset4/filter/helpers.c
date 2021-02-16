#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0; // variable for storing the average
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / (float)3); //calculates the average
            // stores it in the variables
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue; // sepia variables for storing sepia values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // limiting every value to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // replacing the values to the original variables
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp; // creating a variable of the same type to store temporarily in it for swaping
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width + 1) / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];  //creating a temporary array to store the changes of blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // creating different cases else i and j will go out of the grid
            if (i == 0 && j == 0) // case one top left corner
            {
                temp[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                            image[i + 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / (float)4);

                temp[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                             image[i + 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / (float)4);

                temp[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                              image[i + 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / (float)4);
            }
            else if (i == 0 && j == width - 1) // case two top right corner
            {
                temp[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed) / (float)4);

                temp[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                             image[i + 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue) / (float)4);

                temp[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                              image[i + 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen) / (float)4);
            }
            else if (i == height - 1 && j == 0) // case three bottom left corner
            {
                temp[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / (float)4);

                temp[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / (float)4);

                temp[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / (float)4);
            }
            else if (i == height - 1 && j == width - 1) // case four bottom right corner
            {
                temp[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed) / (float)4);

                temp[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                                             image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue) / (float)4);

                temp[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen) / (float)4);
            }
            else if (i == 0 && j != 0 && j != (width - 1)) // case 5 elements in row 1 except the corners
            {
                temp[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed +
                           image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / (float)6);

                temp[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue +
                           image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / (float)6);

                temp[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen +
                           image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / (float)6);
            }
            else if (i == height - 1 && j != 0 && j != (width - 1)) // case 6 elements in bottom row except corners
            {
                temp[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                           image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed) / (float)6);

                temp[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                           image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / (float)6);

                temp[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                           image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / (float)6);
            }
            else if (j == 0 && i != 0 && i != (height - 1)) // case 7 elements in column 1 except corners
            {
                temp[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                           image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed) / (float)6);

                temp[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                           image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue) / (float)6);

                temp[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                           image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen) / (float)6);
            }
            else if (j == (width - 1) && i != 0 && i != (height - 1)) //case 8 elements in right most column except corners
            {
                temp[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed +
                           image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / (float)6);

                temp[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                           image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / (float)6);

                temp[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                           image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / (float)6);
            }
            else // case 9 every other element (basically the ones in the middle)
            {
                temp[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed +
                           image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed +
                           image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / (float)9);

                temp[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                           image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue +
                           image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / (float)9);

                temp[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                           image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen +
                           image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / (float)9);
            }
        }
    }
    // copying the temporary array elements back to the original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
