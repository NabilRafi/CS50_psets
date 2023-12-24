#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int n;
    do
    {
        n = get_int("Start Size: ");
    }
    while (n < 9);

    // Prompt for end size
    int j;
    do
    {
        j = get_int("End Size: ");
    }
    while (j < n);
    
    // Calculate number of years until we reach threshold
    int l;
    for (l = 0; n < j; l++)
    {
        n = n + (n / 3) - (n / 4);
    }

    // Print number of years
    printf("Years: %i\n", l);
}