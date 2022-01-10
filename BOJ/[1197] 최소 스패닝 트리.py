import sys
import heapq

# Kruskal
# PriorityQueue 모듈은 heapq에 동기화 기능이 추가되어 느리다.

#  정점의 개수: V(1 ≤ V ≤ 10,000)
#  간선의 개수: E(1 ≤ E ≤ 100,000)
V, E = map(int, sys.stdin.readline().split())

hq = []
for _ in range(E):
    # A번 정점과 B번 정점이 가중치 C인 간선
    # C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.
    A, B, C = map(int, sys.stdin.readline().split())
    heapq.heappush(hq, (C, [A, B]))


# Disjoint Set----------------------------
parents = [i for i in range(V + 1)]


def find_parent(a):
    if a == parents[a]:
        return a
    parents[a] = find_parent(parents[a])
    return parents[a]


def is_same_parent(a, b):
    return find_parent(a) == find_parent(b)


def union_parent(a, b):
    a_parent = find_parent(a)
    b_parent = find_parent(b)
    if a_parent < b_parent:
        parents[a_parent] = b
    else:
        parents[b_parent] = a


# ----------------------------Disjoint Set


total_weight = 0
while hq:
    weight, [v1, v2] = heapq.heappop(hq)
    if not is_same_parent(v1, v2):
        union_parent(v1, v2)
        total_weight += weight

print(total_weight)
