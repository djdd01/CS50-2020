#include <stdio.h>
#include <cs50.h>
int main(void)
{
    /* creating a string variable and prompting the 
    user for name */
    string name = get_string("what is your name?\n");
    // printing the name 
    printf(" hello , %s!\n", name);
}

