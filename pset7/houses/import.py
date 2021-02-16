from sys import argv, exit
import csv
from cs50 import SQL

# invalid usage if 2 command line arguments are not entered
if len(argv) != 2:
    print("Invalid Usage")
    exit(1)

# creating db to execute sql commands onto
db = SQL("sqlite:///students.db")

# opening characters.csv as a dict reader
with open(argv[1]) as file:
    reader = csv.DictReader(file)
    for row in reader:
        birth = row['birth']
        house = row['house']
        name = row['name']
        namelist = name.split()
        if len(namelist) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       namelist[0], namelist[1], namelist[2], house, birth)
        elif len(namelist) == 2:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       namelist[0], None, namelist[1], house, birth)