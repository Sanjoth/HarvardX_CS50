/**
 * Time For Change C Program
 * Author : Sanjoth Shaw
**/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define QUARTER 25;
#define DIME 10;
#define NICKEL 5;

int main(void) 
{
    // variable declarations
    float given_amount = 0;
    int cent_amount = 0;
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int leftover = 0;
    int coin_count = 0;
    
    // input handling
    printf("O hai! How much change is owed?\n");
        given_amount = GetFloat();
    do 
    {
        //Check if given amount is 0 or less than 0
        if(given_amount == 0||given_amount <= 0)
           {
            printf("How much change is owed?\n");
            given_amount = GetFloat();
           }
            
    }
    while(given_amount <= 0);

    // give amount converted to cents
    cent_amount = (int)round(given_amount*100);

    // quarters
    quarter_count = cent_amount / QUARTER;
    leftover = cent_amount % QUARTER;
    
    // dimes
    dime_count = leftover / DIME;
    leftover = leftover % DIME;
    
    // nickels
    nickel_count = leftover / NICKEL;
    leftover = leftover % NICKEL;
    
    // leftovers i.e pennies
    coin_count = quarter_count + dime_count + nickel_count + leftover;
    
    //Required output:
    printf("%d\n", coin_count);
    
    return 0;
}
