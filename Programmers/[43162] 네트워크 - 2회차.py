from collections import deque


def solution(n, computers):
    answer = 0
    isVisited = [False] * (n + 1)
    for i in range(n):
        if not isVisited[i]:
            answer += 1
            isVisited[i] = True
            queue = deque([i])
            while queue:
                popped = queue.popleft()
                for j in range(n):
                    if j != popped and computers[popped][j]:
                        if not isVisited[j]:
                            isVisited[j] = True
                            queue.append(j)
    return answer
