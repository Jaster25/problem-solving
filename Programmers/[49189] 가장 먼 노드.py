from collections import deque


class Node:
    def __init__(self, data):
        self.data = data
        self.link = deque()

    def connect(self, other):
        self.link.append(other)


def solution(n, edge):
    visited = [0 for _ in range(n + 1)]
    node = [Node(i) for i in range(n + 1)]

    for e in edge:
        node[e[0]].connect(e[1])
        node[e[1]].connect(e[0])

    q = deque([1])
    visited[1] = 1
    while q:
        cur_node = q.popleft()
        for i in node[cur_node].link:
            if not visited[i]:
                visited[i] = visited[cur_node] + 1
                q.append(i)

    return visited.count(max(visited[1:]))


if __name__ == "__main__":
    # n, edge = 6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
    n, edge = 7, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2], [5, 7]]
    print(solution(n, edge))
