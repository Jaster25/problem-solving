from collections import deque
from sys import stdin

T = int(input())

for _ in range(T):
    is_right = True
    s = stdin.readline().rstrip()
    Q = deque()

    for ch in s:
        if ch == "(":
            Q.append(ch)
        else:
            if not Q:
                is_right = False
                break
            else:
                Q.pop()

    if Q:
        is_right = False

    print("YES" if is_right else "NO")