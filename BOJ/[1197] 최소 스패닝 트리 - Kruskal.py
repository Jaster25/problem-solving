import sys
import heapq

v, e = map(int, input().split())

parents = [i for i in range(v + 1)]


def find_parent(a):
    if a == parents[a]:
        return a
    parents[a] = find_parent(parents[a])
    return parents[a]


def is_same_parents(a, b):
    return find_parent(a) == find_parent(b)


def union_parents(a, b):
    a_parent = find_parent(a)
    b_parent = find_parent(b)
    if a_parent < b_parent:
        parents[a_parent] = b
    else:
        parents[b_parent] = a


heap = []
for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    heapq.heappush(heap, [c, a, b])

min_weigth = 0
while heap:
    weight, node1, node2 = heapq.heappop(heap)
    if not is_same_parents(node1, node2):
        union_parents(node1, node2)
        min_weigth += weight

print(min_weigth)
