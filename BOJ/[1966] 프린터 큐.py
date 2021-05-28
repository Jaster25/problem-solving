from sys import stdin
from collections import deque

TC = int(input())

while TC:
    TC -= 1
    N, M = map(int, stdin.readline().split())
    arr = list(map(int, stdin.readline().split()))

    Q = deque()
    for idx, value in enumerate(arr):
        Q.append([value, True if idx == M else False])

    cnt = 0
    while Q:
        if Q[0][0] == max(Q)[0]:
            cnt += 1
            popped = Q.popleft()
            if popped[1]:
                print(cnt)
                break
        else:
            Q.rotate(-1)
