// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//word count
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int initial = word[0]; // checks the first letter of the word
    initial = tolower(initial); // converts it to lowercase
    int place = initial - 97; // a variable place to detect where would be words starting from that letter are stored in the hashtable
    node *cursor = table[place]; // cursor to move in the hashtable

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0) // if the word is same return true
        {
            return true;
        }

        cursor = cursor->next;

    }

    return false; //else false
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    node *n = malloc(sizeof(node));  //allocating memory for the new node in the hashtable
    if (n == NULL)
    {
        fprintf(stderr, "could not create node n\n");  // checking if memory was unable to be allocated
        return 1;
    }

    strcpy(n->word, word); // copying the word in the node
    n->next = NULL;

    int initial = word[0];
    int place = initial - 97;

    if (table[place] == NULL)  //if table is not yet started from that letter
    {
        table[place] = n;
    }
    else // if the table has already been started
    {
        n->next = table[place]->next;
        table[place]->next = n;
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "could not load dictionary\n");
        return false;
    }

    char tempword[LENGTH + 1];
    fscanf(file, "%s", tempword); // scanning once since do while doesnt the first time

    do
    {
        word_count++;
        hash(tempword);
    }
    while (fscanf(file, "%s", tempword) != EOF);

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count; //nothing much just returning the counter
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++) // unloading every memory allocated for the nodes
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor->next;
            free(cursor);
            cursor = temp;
        }
    }

    return true;
}
