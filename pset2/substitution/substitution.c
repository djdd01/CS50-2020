#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // determining correctness of key
    if (argc != 2)
    {
        printf("invalid input\n"); //if there is no key provided
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("key must contain 26 characters\n"); //if the key is invalid
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
        {
        }
        else
        {
            printf("key must only contain alphabets\n"); //if key contains characters other than alphabets
            return 1;
        }
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j] || argv[1][i] == (argv[1][j] + 32) || argv[1][i] == (argv[1][j] - 32))
            {
                printf("Enter each alphabet in key only once\n"); // if the alphabets are repeated
                return 1;
            }
        }
    }

    // getting input
    string plaintext = get_string("plaintext: ");

    // OK so for the main code that does all the work
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if ((plaintext[i] >= 'a' && plaintext[i] <= 'z'))  //checking if the character is lower or uppercase
        {
            // the if and else checks if the character is lower or uppercase and keeps it in the same case by using ascii value maths
            if ((argv[1][plaintext[i] - 97] >= 'a' && argv[1][plaintext[i] - 97] <= 'z'))
            {
                plaintext[i] = argv[1][plaintext[i] - 97];  /* the alphabet is replaced with the character
                in the key where the alphabet would have been had the key were normal alphabets in the correct order.*/
            }
            else
            {
                plaintext[i] = argv[1][plaintext[i] - 97] + 32;
            }
        }
        else if ((plaintext[i] >= 'A' && plaintext[i] <= 'Z'))
        {
            if ((argv[1][plaintext[i] - 65] >= 'a' && argv[1][plaintext[i] - 65] <= 'z'))
            {
                plaintext[i] = argv[1][plaintext[i] - 65] - 32;
            }
            else
            {
                plaintext[i] = argv[1][plaintext[i] - 65] ;
            }
        }
    }

    // printing the final output
    printf("ciphertext: %s\n", plaintext);
    return 0;
}


