import sys
import heapq

# 행성의 수 N (1 ≤ N ≤ 1000)
N = int(sys.stdin.readline())

# 1 ≤ i, j ≤ N, 1 ≤ Cij ≤ 100,000,000, Cij = Cji)
costs = []
for _ in range(N):
    row = list(map(int, sys.stdin.readline().split()))
    costs.append(row)

# Disjoint set
parents = [i for i in range(N + 1)]


def find_parent(a):
    if parents[a] == a:
        return a
    parents[a] = find_parent(parents[a])
    return parents[a]


def is_same_parent(a, b):
    return find_parent(a) == find_parent(b)


def union_parents(a, b):
    a_parent = parents[a]
    b_parent = parents[b]
    if a_parent < b_parent:
        parents[a_parent] = b
    else:
        parents[b_parent] = a


# Kruskal
hq = []
for i in range(N):
    for j in range(i + 1, N):
        heapq.heappush(hq, (costs[i][j], [i, j]))

total = 0
while hq:
    cost, (planet1, planet2) = heapq.heappop(hq)
    if not is_same_parent(planet1, planet2):
        union_parents(planet1, planet2)
        total += cost

print(total)
