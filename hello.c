#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Type in your name for greeting
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}