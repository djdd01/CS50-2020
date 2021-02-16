from sys import exit
from cs50 import get_int

# ok so first of all creating a long variable to get a card number as an input
card = get_int("What is your credit card number? \n")
temp = card  # creating another variable temp to utilize instead of making changes in card
alt = 0  # alternate digits
adj = 0  # alt alternate digits (that are not muliplied by 2) ( dont know y i named it adj since they are not adjacent)
while temp > 0:
    # now this loop is complicated since it does many mathematical operations in one line
    adj = adj + temp % 10
    """ the next line is very messy but start from the innermost bracket and u will understand.
    i took the alternate digits, multiplied them by 2 then seperated the digits of the products and finally added them """
    alt = alt + ((2 * ((temp % 100) // 10)) % 10) + ((2 * ((temp % 100) // 10)) // 10)
    temp = temp // 100

temp = card  # replaces the value of temp with card again for further use
total = alt + adj
valid = False  # created a variable to store if the card is valid
if total % 10 == 0:
    valid = True

else:
    print("INVALID\n")
    exit(1)


# calculating the number of digits
i = 0
digit = False
if valid == True:
    while temp > 0:
        temp = temp // 10
        i = i + 1
    temp = card

# checking the initial digits of the cards
if i == 15:
    temp = temp // pow(10, 13)
    if temp == 34 or temp == 37:  # since american express cards start with these
        print("AMEX\n")
        exit(0)
    else:
        print("INVALID\n")
        exit(1)

temp = card
if i == 16:
    temp = temp // pow(10, 14)
    if temp == 51 or temp == 52 or temp == 53 or temp == 54 or temp == 55:
        # since mastercards start with these
        print("MASTERCARD\n")
        exit(0)
    else:
        temp = temp // 10
        if temp == 4:    # nesting an if-else statement as master and visa both have 16 digit card numbers
            print("VISA\n")
            exit(0)
        else:
            print("INVALID\n")
            exit(1)

temp = card
if i == 13:
    temp = temp // pow(10, 12)
    if temp == 4:
        print("VISA\n")
        exit(0)
    else:
        print("INVALID\n")
        exit(1)
else:
    print("INVALID\n")
    exit(1)
