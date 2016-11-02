/**
 * Generate the mario half-pyramid using "#" for blocks.
 * Made By Sanjoth Shaw
**/

#include <stdio.h>
#include <cs50.h>
 
int main(void)
{
 
    // variable declaration
    int height = -1;
    int rows;
    int space;
    int hash;
 
    // Prompts user an input b/w 0 to 23
    while ((height < 0) || (height > 23))
    {
        printf("height: ");
        height = GetInt();
    }
 
    // loop for traversing rows (1 to 8)
    for (rows = 1; rows <= height; rows++) 
    {
        //loop for inserting space
        for (space = (height - rows); space > 0; space--)
        {
            printf(" "); 
        }
        
        //loop for inserting "#""
        for (hash = 1; hash <= (rows + 1); hash++)
        {   
            printf("#"); 
        }
 
        printf("\n");
    }
    return 0;
}
