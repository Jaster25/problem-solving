import re


T = int(input())

for _ in range(T):
    s = input()
    if re.fullmatch("((100+1+)|01)+", s):
        print("YES")
    else:
        print("NO")
