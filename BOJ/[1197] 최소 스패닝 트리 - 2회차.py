import sys
import heapq

V, E = map(int, sys.stdin.readline().split())
parents = [i for i in range(V + 1)]


def find_parent(a):
    if a == parents[a]:
        return a

    parents[a] = find_parent(parents[a])
    return parents[a]


def is_same_parents(a, b):
    return find_parent(a) == find_parent(b)


def union_parents(a, b):
    a_parent = parents[a]
    b_parent = parents[b]
    if a_parent < b_parent:
        parents[a_parent] = b
    else:
        parents[b_parent] = a


edges = []
for _ in range(E):
    A, B, C = map(int, sys.stdin.readline().split())
    heapq.heappush(edges, [C, A, B])

mst = 0
while edges:
    weight, a, b = heapq.heappop(edges)
    if not is_same_parents(a, b):
        union_parents(a, b)
        mst += weight

print(mst)
