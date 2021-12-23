import sys
from collections import deque

# (0 ≤ n ≤ 100)


def get_distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


# 한 번 이동 시 최대 거리 1000미터
def is_possible(a, b):
    return get_distance(a, b) <= 1000


t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    stores = []
    start = list(map(int, sys.stdin.readline().split()))
    for _ in range(n):
        store = list(map(int, sys.stdin.readline().split()))
        stores.append(store)
    goal = list(map(int, sys.stdin.readline().split()))

    is_arrived = False
    queue = deque([start])
    is_visited = [False] * n
    while queue:
        popped = queue.popleft()
        if is_possible(popped, goal):
            is_arrived = True
            break

        for i in range(len(stores)):
            if not is_visited[i] and is_possible(popped, stores[i]):
                queue.append(stores[i])
                is_visited[i] = True

    if is_arrived:
        print("happy")
    else:
        print("sad")
