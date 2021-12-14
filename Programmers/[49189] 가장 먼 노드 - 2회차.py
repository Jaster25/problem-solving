from collections import deque


def solution(n, edge):
    graph = [Node(i) for i in range(n + 1)]
    for (a, b) in edge:
        graph[a].connect(b)
        graph[b].connect(a)

    queue = deque([1])
    isVisited = [-1, 0] + [-1] * n
    while queue:
        number = queue.popleft()
        for connectedNode in graph[number].connected:
            if isVisited[connectedNode] == -1:
                queue.append(connectedNode)
                isVisited[connectedNode] = isVisited[number] + 1

    answer = isVisited.count(max(isVisited))
    return answer


class Node:
    def __init__(self, number):
        self.number = number
        self.connected = []

    def connect(self, connectedNodeNumber):
        self.connected.append(connectedNodeNumber)
