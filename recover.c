#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8
bool new_jpeg(BYTE buffer[]);
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *startfile = fopen(argv[1], "r");
    if (!startfile)
    {
        printf("Error in File\n");
        return 1;
    }
    
    BYTE buffer[BLOCK_SIZE];
    int file_count = 0;
    bool found_jpg = false;
    FILE *endfile;
    while (fread(buffer, BLOCK_SIZE, 1, startfile))
    {
        if (new_jpeg(buffer))
        {
            if(!found_jpg)
            {
                found_jpg = true;
            }
            else
            {
                fclose(endfile);
            }
            char filename[FILE_NAME_SIZE];
            sprintf(filename, "%03i.jpg", file_count++);
            endfile = fopen(filename, "w");
            if (!endfile)
            {
                return 1;
            }   
            fwrite(buffer, BLOCK_SIZE, 1, endfile);
        }
        else if (found_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, endfile);
        }
    }
    fclose(endfile);
    fclose(startfile);
}
bool new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}