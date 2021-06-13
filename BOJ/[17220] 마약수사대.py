from sys import stdin
from collections import deque


graph = [[] for _ in range(27)]
N, M = map(int, stdin.readline().split())
root = [i for i in range(N)]
visited = [False for _ in range(N)]


def toASCIIIdx(ch):
    return ord(ch) - ord("A")


for _ in range(M):
    provider, receiver = map(lambda x: toASCIIIdx(x), stdin.readline().strip().split())
    graph[provider].append(receiver)
    if receiver in root:
        root.remove(receiver)


caughtProviders = list(map(lambda x: toASCIIIdx(x), stdin.readline().strip().split()[1:]))
for caughtProvider in caughtProviders:
    if caughtProvider in root:
        root.remove(caughtProvider)

answer = -len(root)
queue = deque(root)
for num in root:
    visited[num] = True

while queue:
    answer += 1
    provider = queue.popleft()
    for receiver in graph[provider]:
        if not receiver in caughtProviders:
            if not visited[receiver]:
                queue.append(receiver)
                visited[receiver] = True


print(answer)