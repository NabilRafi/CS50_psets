#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for user input
    int x;
    do 
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);
    
    // Prompt for creating bricks and spaces
    for (int n = 0; n < x; n++)
    {
        for (int j = x - 1; j > n; j--)
        {
            printf(" ");
        }
        for (int k = -1; k < n; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = -1; k < n; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
