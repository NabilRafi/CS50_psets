// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Hashtable_Size 1000
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];
node *hashtable[Hashtable_Size];

unsigned int num_words = 0;
bool is_loaded_dict = false;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char check_word[strlen(word)];
    strcpy(check_word, word);
    for (int i = 0; check_word[i] != '\0'; i++)
    {
        check_word[i] = tolower(check_word[i]);
    }
    int index = hash(check_word);
    if (hashtable[index] != NULL)
    {
        for (node *node_pointer = hashtable[index]; node_pointer != NULL; node_pointer = node_pointer->next)
        {
            if (strcmp(node_pointer->word, check_word) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 0;
    int n;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else
        {
            n = 27;
        }
        hash = ((hash << 3) + n) % Hashtable_Size;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *start_file = fopen(dictionary, "r");
    if (start_file == NULL)
    {
        return false;
    }
    for (int i = 0; i < Hashtable_Size; i++)
    {
        hashtable[i] = NULL;
    }
    char word[LENGTH + 1];
    node *new_node_pointer;
    while (fscanf(start_file, "%s", word) != EOF)
    {
        num_words++;
        do
        {
            new_node_pointer = malloc(sizeof(node));
            if (new_node_pointer == NULL)
            {
                free(new_node_pointer);
            }
            
        }
        while (new_node_pointer == NULL);
        
        strcpy(new_node_pointer->word, word);
        int index = hash(word);
        if (hashtable[index] == NULL)
        {
            new_node_pointer->next = NULL;
            hashtable[index] = new_node_pointer;
        }
        else
        {
            new_node_pointer->next = hashtable[index];
            hashtable[index] = new_node_pointer;
        }
    }
    fclose(start_file);
    is_loaded_dict = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (!is_loaded_dict)
    {
        return 0;
    }
    return num_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    if (!is_loaded_dict)
    {
        return false;
    }
    for (int i = 0; i < Hashtable_Size; i++)
    {
        if (hashtable[i] != NULL)
        {
            node *p = hashtable[i];
            while (p != NULL)
            {
                node *tmp_p = p;
                p = p->next;
                free(tmp_p);
            }
        }
    }
    return true;
}






















