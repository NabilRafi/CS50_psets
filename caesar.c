#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    string plain_text = get_string("Plain Text: ");

    printf("ciphertext: ");
    
    int x = atoi(argv[1]);
    for (int z = 0; z < strlen(plain_text); z++)
    {
        char c = plain_text[z];
        
        if (isalpha(c))
        {
            char t = 'A';
            if (islower(c))
            {
                t = 'a';
            }
            printf("%c", (c - t + x) % 26 + t);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}