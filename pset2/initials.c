#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    
    string name;
    name = GetString();
    
    // Get the no. of characters from user
    int n = strlen(name);
    
    printf("%c",toupper(name[0]));
    
   // Printing initial after space as uppercase.
   for (int i = 0; i < n; i++)
   {
       if(name[i] == ' ')
       {
           printf("%c",toupper(name[i+1]));
       }
   }
   printf("\n");
    
}

