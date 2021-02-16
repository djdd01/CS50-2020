from cs50 import get_int


def main():
    height = get_positive_int()  # getting input from user for the height

    for i in range(height):  # loop
        print((height - i - 1) * ' ', end='')
        print((i + 1) * '#', end='  ')
        print((i + 1) * '#')


def get_positive_int():
    while True:
        n = get_int("height of pyramid: ")
        if n > 0 and n < 9:
            break

    return n


main()