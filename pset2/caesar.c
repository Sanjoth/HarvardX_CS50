#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string args[])
{
    int k;
    
    //Checking for 2 command line arguments
    if (argc == 2)
    {
        // Converting String to Integer
        k = atoi(args[1]);
    }
    else
    {
        printf("INSERT ONLY 2 ARGUMENTS !\n");
       return 1;
    }   
   
    string p = GetString();
    int n = strlen(p);
    
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        // Check upper case & encrypt
        if (isupper(p[i]))
        {
            c = ((p[i] + k - 65) % 26) + 65;
            printf("%c",c);
        }
        // Check lower case & encrypt
        else if (islower(p[i]))
        {
            c = ((p[i] + k - 97) % 26) + 97;
            printf("%c",c);
        }
        else
        {
            printf("%c",p[i]);
        }
    }
    printf("\n");
}