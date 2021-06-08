from sys import stdin
from collections import deque

TC = int(stdin.readline())

while TC:
    TC -= 1
    A, B = map(int, stdin.readline().split())
    visited = [False for _ in range(10001)]

    queue = deque([[A, ""]])
    visited[A] = True

    while queue:
        registry, order = queue.popleft()
        if registry == B:
            print(order)
            break

        curRegistryStr = ("0000" + str(registry))[len(str(registry)) :]

        # D
        newRegistry = registry * 2 % 10000
        if not visited[newRegistry]:
            visited[newRegistry] = True
            queue.append([newRegistry, order + "D"])

        # S
        newRegistry = registry - 1 if registry else 9999
        if not visited[newRegistry]:
            visited[newRegistry] = True
            queue.append([newRegistry, order + "S"])

        # L
        newRegistry = "" + curRegistryStr[1:] + curRegistryStr[0]
        if not visited[int(newRegistry)]:
            visited[int(newRegistry)] = True
            queue.append([int(newRegistry), order + "L"])

        # R
        newRegistry = curRegistryStr[3] + curRegistryStr[:-1]
        if not visited[int(newRegistry)]:
            visited[int(newRegistry)] = True
            queue.append([int(newRegistry), order + "R"])