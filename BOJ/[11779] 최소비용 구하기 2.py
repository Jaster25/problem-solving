from collections import deque
from sys import stdin


N = int(input())
M = int(input())
bus = [[] for _ in range(N + 1)]
d_cost = [-1 for _ in range(N + 1)]
d_path = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b, cost = map(int, stdin.readline().split())
    bus[a].append([cost, b])

start, end = map(int, stdin.readline().split())

d_cost[start] = 0
d_path[start] = [start]
Q = deque([start])

while Q:
    popped = Q.popleft()
    for cost, i in bus[popped]:
        if d_cost[i] == -1 or d_cost[i] > d_cost[popped] + cost:
            d_cost[i] = d_cost[popped] + cost
            d_path[i] = d_path[popped][:]
            d_path[i].append(i)
            Q.append(i)

print(d_cost[end])
print(len(d_path[end]))
for i in d_path[end]:
    print(i, end=" ")
