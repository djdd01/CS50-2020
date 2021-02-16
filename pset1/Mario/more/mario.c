#include <cs50.h>
#include <stdio.h>

int main(void)
{  
    // creating a variable in main to avoid problems related to scope 
    int height;
    do
    {
        height = get_int("What should be the height of the pyramid? \n");
    } 
    while (height < 1 || height > 8);
    // loop nesting (loop 1 for rows and loop 2 for columns)
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j <= (2 * height) + 1; j++)
        {
            // not all conditon (boolean expressions) are obvious , some i had to put values to decide 
            if (j < height - i)
            {
                printf(" ");  
            }
            else if (j == height + 1)
            {
                printf("  ");
            }
            else if (j >= height - i && j < height + 1)
            {
                printf("#");
            }
            else if (j > height + 1 && j <= height + i + 2)
            {
                printf("#");
            }
            /* i used just one loop although i could have used another, with another counter 'k', 
            for the right part of the pyramid */
        }
        printf("\n");
    }
}
