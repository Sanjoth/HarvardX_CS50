#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string args[])
{
    string k;
    
    // Checking if 2 arguments specified 
    if (argc == 2)
    {
        k = args[1];
    }
    else
    {
        printf("PLEASE SPECIFY 2 ARGS !\n");
        return 1;
    }
    
    //Length of key
    int m = strlen(k);
    
    //Check if key is alphabetic
    for (int i = 0; i < m; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("KEYS MUST ME ALPHABETIC ONLY ! \n");
            return 1;
        }
    }
    
    // Getting input string from user
    string p = GetString();
    
    //Length of user input
    int n = strlen(p);
    
    for (int i = 0,j = 0; i < n; i++)
    {   
        char c;
        // Get key for this iteration
        int KeyLetter = tolower(k[j % m]) - 'a';
        
        // Keep case of letter
        if (isupper(p[i]))
        {
            c = 'A' + (p[i] - 'A' + KeyLetter) % 26;
            printf("%c",c);
            j++;
        }
        else if(islower(p[i]))
        {
            c = 'a' + (p[i] - 'a' + KeyLetter) % 26;
            printf("%c",c);
            j++;
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}