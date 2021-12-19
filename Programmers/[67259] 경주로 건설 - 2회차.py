from collections import deque


def solution(board):
    answer = []
    n = len(board)
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    # y, x, last direction: cost
    isVisited = {(0, 0, 0): 0, (0, 0, 1): 0, (0, 0, 2): 0, (0, 0, 3): 0}
    queue = deque([(0, 0, -1, 0)])
    while queue:
        y, x, d, cost = queue.popleft()
        if y == n - 1 and x == n - 1:
            answer.append(cost)
            continue

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < n and 0 <= nx < n:
                if board[ny][nx] == 0:
                    newCost = cost + 100
                    # 코너
                    if d != -1 and d % 2 != i % 2:
                        newCost += 500
                    if isVisited.get((ny, nx, i)) is None or isVisited.get((ny, nx, i)) > newCost:
                        isVisited[(ny, nx, i)] = newCost
                        queue.append((ny, nx, i, newCost))
    return min(answer)
