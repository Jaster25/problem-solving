from collections import deque
from sys import stdin

T = int(input())

Q = deque()

for _ in range(T):
    s = stdin.readline().rstrip()

    if " " in s:
        order, num = s.split()
    else:
        order = s

    if order == "push":
        Q.append(num)
    elif order == "pop":
        print(Q.popleft() if Q else -1)
    elif order == "size":
        print(len(Q))
    elif order == "empty":
        print(0 if Q else 1)
    elif order == "front":
        print(Q[0] if Q else -1)
    elif order == "back":
        print(Q[-1] if Q else -1)
