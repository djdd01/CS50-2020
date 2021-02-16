#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declaring the varible in main to avoid problems related to scope
    int height;
    // creating a do-while loop 
    do
    {    
        //getting the height 
        height = get_int("Enter the height of the pyramid:\n");
    } 
    while (height < 1 || height > 8);
    // nesting loops, first for the rows and 2nd for the columns
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            if (j < height - i) 
            {
                printf(" ");
            }
            else 
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
