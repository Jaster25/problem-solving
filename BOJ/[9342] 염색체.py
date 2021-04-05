import re


T = int(input())

for _ in range(T):
    s = input()
    if re.match("^[A-F]?A+F+C+[A-F]?$", s):
        print("Infected!")
    else:
        print("Good")
