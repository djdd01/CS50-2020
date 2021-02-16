#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // creating 4 varibles each for quarters, dimes, nickles and pennies
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;
    float owed;
    int cents;
    do 
    {
        owed = get_float("how much change is owed to you? \n");
    }
    while (owed < 0);
    cents = round(owed * 100); // cinverting dollars into cents
    while (cents > 0)
    {
        if (cents >= 25)
        {
            q++;   //incrementing quarters 
            cents -= 25;
        }
        else if (cents < 25 && cents >= 10)
        {
            d++;   //incrementing dimes
            cents -= 10;
        }
        else if (cents < 10 && cents >= 5)
        {
            n++;   //incrementing nickles
            cents -= 5;
        }
        else
        {
            p++;   //incrementing pennies
            cents -= 1;
        }
    }

    printf("%i\n", q + d + n + p);
}
