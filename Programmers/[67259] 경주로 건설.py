from collections import deque


def bfs():
    visited = {(0, 0, 0): 0, (0, 0, 1): 0, (0, 0, 2): 0, (0, 0, 3): 0}
    dy, dx = [-1, 0, 1, 0], [0, -1, 0, 1]

    Q = deque([(0, 0, -1, 0)])

    while Q:
        y, x, last_dir, cost = Q.popleft()
        if y == N-1 and x == N-1:
            answer.append(cost)
            continue
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < N:
                if not board_[ny][nx]:
                    if last_dir == i or last_dir == (i+2) % 4 or last_dir == -1:
                        new_cost = cost + 100
                    else:
                        new_cost = cost + 600
                    if visited.get((ny, nx, i)) is None or visited.get((ny, nx, i)) > new_cost:
                        visited[(ny, nx, i)] = new_cost
                        Q.append([ny, nx, i, new_cost])


def solution(board):
    global N, answer, board_
    board_ = [i[:] for i in board]
    N = len(board_)
    answer = []

    bfs()

    return min(answer)


if __name__ == "__main__":
    # board = [[0, 0, 1], [0, 0, 0], [1, 0, 0]]
    # board = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    # board = [[0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0], [
    #     0, 0, 0, 1, 0, 0, 0, 1], [0, 0, 1, 0, 0, 0, 1, 0], [0, 1, 0, 0, 0, 1, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0]]
    # board = [[0, 0, 1, 0], [0, 0, 0, 0], [0, 1, 0, 1], [1, 0, 0, 0]]
    board = [[0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 0], [0, 0, 1, 0, 0, 0],
             [1, 0, 0, 1, 0, 1], [0, 1, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0]]
    print(solution(board))
