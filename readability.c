#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string Text); 
int count_words(string Text);
int count_sentences(string Text);
int grade_level(int letters, int words, int sentences);

int main(int argc, string argv[])
{
    // Prompt for user input
    string Text = get_string("Text: ");
    
    // Counting the number of letters
    int letters = count_letters(Text);
    printf("%i letter(s)\n", letters);
    
    // Counting the number of words
    int words = count_words(Text);
    printf("%i word(s)\n", words);
    
    // Counting the number of sentences
    int sentences = count_sentences(Text);
    printf("%i sentence(s)\n", sentences);
    
    // Calculating and printing grade level
    int gradelevel = grade_level( letters, words, sentences);
    if (gradelevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (gradelevel <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", gradelevel);
    }
}

// Program for count_letters function
int count_letters(string Text)
{
    int l = 0;
    for (int i = 0; i < strlen(Text); i++)
    {
        if (isalpha(Text[i]))
        {
            l++;
        }
    }
    return l;
}

// Program for count_words function
int count_words(string Text)
{
    int w = 0;
    for (int n = 0; n < strlen(Text); n++)
    {
        if (isspace(Text[n]))
        {
            w++;
        }
    }
    return w + 1;
}

// Program for count_sentences function
int count_sentences(string Text)
{
    int s = 0;
    for (int r = 0; r < strlen(Text); r++)
    {
        if (Text[r] == '.' || Text[r] == '!' || Text[r] == '?')
        {
            s++;
        }
    }
    return s;
}

// Program for grade_level function
int grade_level(int letters, int words, int sentences)
{
    
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    float x = 0.0588 * L - 0.296 * S - 15.8;
    int y = round(x);
    return y;
}
