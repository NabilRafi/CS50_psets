#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt user for input
    float x;
    do
    {
        x = get_float("Change Owed: ");
    }
    while (x < 0);
    
    // Conversion from dollars to cents
    int y = round(x * 100);
    
    // Calculation
    int i = 25, j = 10, k = 5, l = 1, coins = 0;
    while (y >= i)
    {
        y = y - i;
        coins++;
    }
    while (y >= j)
    {
        y = y - j;
        coins++;
    }
    while (y >= k)
    {
        y = y - k;
        coins++;
    }
    while (y >= l)
    {
        y = y - l;
        coins++;
    }
    // Printing the coins
    printf("Coins: %i\n", coins);
}