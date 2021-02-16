from sys import argv
from cs50 import SQL

# invalid usage if 2 command line arguments are not entered
if len(argv) != 2:
    print("Invalid Usage")
    exit(1)

# creating db to execute sql commands on
db = SQL("sqlite:///students.db")

# saving output of sql query in a dictionary called dict
Dict = db.execute("SELECT first, middle, last, birth from students where house = ? order by last asc, first asc", argv[1])

# for every row , printing as per required by the question
for row in Dict:
    first = row['first']
    middle = row['middle']
    last = row['last']
    birth = row['birth']
    if middle != None:
        print(f"{first} {middle} {last}, {birth}")
    else:
        print(f"{first} {last}, {birth}")