import sys

# Python 3으로 제출, PyPy3은 메모리 초과
sys.setrecursionlimit(6 * 10 ** 5)

n, m = map(int, sys.stdin.readline().split())

parents = list(i for i in range(n + 1))


def find_parent(a):
    if parents[a] == a:
        return a
    parents[a] = find_parent(parents[a])
    return parents[a]


def is_same_parents(a, b):
    return find_parent(a) == find_parent(b)


def union_parents(a, b):
    a_parent = parents[a]
    b_parent = parents[b]
    if a_parent < b_parent:
        parents[a_parent] = b_parent
    else:
        parents[b_parent] = a_parent


for i in range(1, m + 1):
    dot1, dot2 = map(int, sys.stdin.readline().split())
    if is_same_parents(dot1, dot2):
        print(i)
        break
    union_parents(dot1, dot2)
else:
    print(0)
