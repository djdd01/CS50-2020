#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    float letters = 0; // keeping the variables as floating point as they will be calculated per 100 words later
    float words = 0;
    float sentences = 0;

    string text = get_string("Enter the text here: \n"); //string input
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        else if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }
    //an extra 'words' increment as there will be no space after the last word so it will not be counted
    words++;
    //calculating letters and sentences per 100 words
    letters = (letters / words) * 100;
    sentences = (sentences / words) * 100;

    //calculating the index
    int index = round(0.0588 * letters - 0.296 * sentences - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
