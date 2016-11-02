/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define ARRAY_SIZE 27

typedef struct trie_node{
    bool isWord;
    struct trie_node* next[ARRAY_SIZE];
} node;

// Declarations
void deallocate(node* trie_pointer);

node* first;
unsigned int dictSize = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // Check if first node is initialized and dictionary is loaded
    if (first == NULL)
    {
        printf("Error checking word '%s', because the dictionary not being loaded or first node not initialized.",word);
        return false;
    }
    
    node* cur = first;
    int n = strlen(word);
    
    for(int i = 0; i < n; i++)
    {
        // Change character to lower case first and then find index
        int c = tolower(word[i]);
        
        if (c == '\'')
            c = 26;
        else
            c = c - 'a';
            
        // Check the index if its pointing to null else traverse through the nodes
        if (cur -> next[c] == NULL)
            return false;
        else
            cur = cur -> next[c];
    }
    
    // Return true if current points to the end of a word
    if(cur -> isWord)
        return true;
    else
        return false;

}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
     // Allocate the first node
    first = malloc(sizeof(node));
    
    // Open the dictionary ile
    FILE* f1 = fopen(dictionary, "r");
    if (f1 == NULL)
    {
        printf("Couldn't open %s.\n", dictionary);
        return false;
    }
    
    // Pointer to track the current position
    node* cur = first;
    
    // Loop through the dictionary, reading character by character
    for (int c = fgetc(f1); c != EOF; c = fgetc(f1))
    {
        // Check for alphabet or apostrophe
        if (isalpha(c) || (c == '\''))
        {
            // Convert the character c to its proper array infex
            if (c == '\'')
                c = 26;
            else 
                c = c-'a';
            
            // Allocate memory for the next node if not allocated
            if(cur -> next[c] == NULL)
            {
                cur -> next[c] = malloc(sizeof(node));
            }
            
            // Move on to the next node
            cur = cur -> next[c];
        }
        
        else if (c == '\n')
        {
            cur -> isWord = true;
            // Reset the pointer for a new word
            cur = first;
            // Increase the count of words in dictionary
            dictSize++;
        }
        
    }
    fclose(f1);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
   return dictSize;

}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
   deallocate(first);
    return true;
}

void deallocate(node* trie_pointer)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (trie_pointer -> next[i] != NULL)
        {
            deallocate(trie_pointer -> next[i]);
        }
    }
    free(trie_pointer);
    
}
