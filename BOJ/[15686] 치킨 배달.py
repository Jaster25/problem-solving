from sys import stdin
from itertools import combinations


N, M = map(int, stdin.readline().split())
chickens = []
homes = []
MAP = [list(map(int, stdin.readline().split())) for _ in range(N)]

# 0: 빈곳 1: 집, 2: 치킨집
for i in range(N):
    for j in range(N):
        if MAP[i][j] == 1:
            homes.append([i, j])
        elif MAP[i][j] == 2:
            chickens.append([i, j])

min_total = float("inf")
for open_chickens in combinations(chickens, M):
    total = 0
    for home in homes:
        distance = float("inf")
        for chicken in open_chickens:
            distance = min(distance, abs(home[0] - chicken[0]) + abs(home[1] - chicken[1]))
        total += distance
    min_total = min(min_total, total)

print(min_total)
