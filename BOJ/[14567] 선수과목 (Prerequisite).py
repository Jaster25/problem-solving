import sys
from collections import deque

# Topological sort
class Node:
    def __init__(self, number):
        self.number = number
        self.inner = []
        self.outer = []


N, M = map(int, sys.stdin.readline().split())
graph = [Node(i) for i in range(N + 1)]
for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    graph[B].inner.append(A)
    graph[A].outer.append(B)

queue = deque()
for i in range(1, N + 1):
    if not graph[i].inner:
        queue.append(i)

answer = [0] * N
current_semester = 1
while queue:
    for _ in range(len(queue)):
        popped = queue.popleft()
        if answer[popped - 1]:
            continue

        answer[popped - 1] = current_semester
        for i in graph[popped].outer:
            graph[i].inner.remove(popped)
            if not graph[i].inner:
                queue.append(i)
    current_semester += 1

for i in answer:
    print(i, end=" ")
