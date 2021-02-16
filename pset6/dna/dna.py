import cs50  # importing libraries
import sys
import csv

if len(sys.argv) != 3:
    print("Invalid Usage")

f = open(sys.argv[2], "r")  # opening sequence file

# max variables
strAGATCmax = 0
strAATGmax = 0
strTATCmax = 0
strTCTGmax = 0

sequence = f.read()

# calculating AGATC
for i in range(len(sequence)):
    strAGATC = 0
    j = i
    while sequence[j:j + 5] == 'AGATC':
        strAGATC += 1
        j = j + 5
        if strAGATC > strAGATCmax:
            strAGATCmax = strAGATC

# calculating AATG
for i in range(len(sequence)):
    strAATG = 0
    j = i
    while sequence[j:j + 4] == 'AATG':
        strAATG += 1
        j = j + 4
        if strAATG > strAATGmax:
            strAATGmax = strAATG

# calculating TATC
for i in range(len(sequence)):
    strTATC = 0
    j = i
    while sequence[j:j + 4] == 'TATC':
        strTATC += 1
        j = j + 4
        if strTATC > strTATCmax:
            strTATCmax = strTATC

# calculating TCTG
for i in range(len(sequence)):
    strTCTG = 0
    j = i
    while sequence[j:j + 4] == 'TCTG':
        strTCTG += 1
        j = j + 4
        if strTCTG > strTCTGmax:
            strTCTGmax = strTCTG

# comparing
if sys.argv[1] == 'databases/large.csv':
    with open(sys.argv[1], 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            if row[1] == str(strAGATCmax) and row[8] == str(strTCTGmax) and row[3] == str(strAATGmax) and row[6] == str(strTATCmax):
                print(row[0])
                exit(0)
        print("No match")
        exit(0)

# comparing
if sys.argv[1] == 'databases/small.csv':
    with open(sys.argv[1], 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            if row[2] == str(strAATGmax) and row[3] == str(strTATCmax):
                print(row[0])
                exit(0)
        print("No match")
        exit(0)