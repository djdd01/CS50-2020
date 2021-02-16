#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{ 
    // ok so first of all creating a long variable to get a card number as an input
    long card = get_long("What is your credit card number? \n");
    long temp = card; // creating another variable temp to utilize instead of making changes in card 
    int alt = 0; // alternate digits
    int adj = 0; // alt alternate digits (that are not muliplied by 2) ( dont know y i named it adj since they      are not adjacent)
    while (temp > 0)
    {
        // now this loop is complicated since it does many mathematical operations in one line
        adj = adj + temp % 10;
        /* the next line is very messy but start from the innermost bracket and u will understand.
        i took the alternate digits, multiplied them by 2 then seperated the digits of the products and finally         added them */
        alt = alt + ((2 * ((temp % 100) / 10)) % 10) + ((2 * ((temp % 100) / 10)) / 10) ;
        temp = temp / 100;
    }
    temp = card; // replaces the value of temp with card again for further use
    int total = alt + adj; 
    bool valid = false; // created a variable to store if the card is valid
    if (total % 10 == 0)
    {
        valid = true;
    }
    else 
    {
        printf("INVALID\n");
        return 0;
    }

    // calculating the number of digits
    int i = 0;
    bool digit = false;
    if (valid == true)
    {
        while (temp > 0)
        {
            temp = temp / 10;
            i++;
            
        }
        temp = card;
    }

    // checking the initial digits of the cards
    if (i == 15)
    {
        temp = temp / pow(10, 13);
        if (temp == 34 || temp == 37) // since american express cards start with these
        {
            printf("AMEX\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    temp = card;
    if (i == 16)
    {
        temp = temp / pow(10, 14);
        if (temp == 51 || temp == 52 || temp == 53 || temp == 54 || temp == 55) 
            // since mastercards start with these
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            temp = temp / 10;
            if (temp == 4)    // nesting an if-else statement as master and visa both have 16 digit card numbers
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }
    temp = card;
    if (i == 13)
    {
        temp = temp / pow(10, 12);
        if (temp == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
