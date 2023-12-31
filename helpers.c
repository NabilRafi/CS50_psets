#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int avg = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }

}

int cap(int number)
{
    if (number > 255)
    {
        return 255;
    }
    else
    {
        return number;
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int originalRed = pixel.rgbtRed;
            int originalGreen = pixel.rgbtGreen;
            int originalBlue = pixel.rgbtBlue;
            image[i][j].rgbtRed = cap(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            image[i][j].rgbtGreen = cap(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            image[i][j].rgbtBlue = cap(round(0.272 * originalRed + 0.534 *originalGreen + 0.131 * originalBlue));
            
        }
    }
}

void swap(RGBTRIPLE * pixel1, RGBTRIPLE * pixel2)
{
    RGBTRIPLE tmp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}

bool valid_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}


RGBTRIPLE get_blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int RedValue = 0, BlueValue = 0, GreenValue = 0;
    int Num_Of_Valid_Pixels = 0;
    for (int ci = -1; ci <= 1; ci++)
    {
        for (int cj = -1; cj <= 1; cj++)
        {
            int new_i = i + ci;
            int new_j = j + cj;
            if(valid_pixel(new_i, new_j, height, width))
            {
                Num_Of_Valid_Pixels++;
                RedValue += image[new_i][new_j].rgbtRed;
                GreenValue += image[new_i][new_j].rgbtGreen;
                BlueValue += image[new_i][new_j].rgbtBlue;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float) RedValue / Num_Of_Valid_Pixels);
    blurred_pixel.rgbtGreen = round((float) GreenValue / Num_Of_Valid_Pixels);
    blurred_pixel.rgbtBlue = round((float) BlueValue / Num_Of_Valid_Pixels);
    return blurred_pixel;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = get_blurred_pixel(i, j, height, width, image);
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
}
