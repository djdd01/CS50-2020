from sys import exit
from cs50 import get_string

letters = 0  # keeping the variables as floating point as they will be calculated per 100 words later
words = 0
sentences = 0

text = get_string("Enter the text here: \n")  # string input
for i in range(len(text)):
    if text[i] == ' ':
        words += 1
    elif text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentences += 1
    elif (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letters += 1

# an extra 'words' increment as there will be no space after the last word so it will not be counted
words += 1
# calculating letters and sentences per 100 words
letters = (letters / words) * 100
sentences = (sentences / words) * 100

# calculating the index
index = round(0.0588 * letters - 0.296 * sentences - 15.8)
if index < 1:
    print("Before Grade 1\n")
elif index > 16:
    print("Grade 16+\n")
else:
    print(f"Grade {index}")

