import sys

# 3 <= N <= 50
N = int(sys.stdin.readline())
board = []
for i in range(N):
    board.append(list(sys.stdin.readline()))

# 사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.
# C: 빨간색
# P: 파란색
# Z: 초록색
# Y: 노란색


def count_candy(y, x):
    candy = board[y][x]

    count_height = 1
    up = 1
    while y - up >= 0 and board[y - up][x] == candy:
        up += 1
        count_height += 1
    down = 1
    while y + down < N and board[y + down][x] == candy:
        down += 1
        count_height += 1

    count_width = 1
    left = 1
    while x - left >= 0 and board[y][x - left] == candy:
        left += 1
        count_width += 1
    right = 1
    while y + right < N and board[y][x + right] == candy:
        right += 1
        count_width += 1

    return max(count_height, count_width)


# 오른쪽, 아래 방향만 확인 (중복 제거)
dy = [0, 1]
dx = [1, 0]

max_candy_count = 0

for y in range(N):
    for x in range(N):
        for d in range(2):
            ny = y + dy[d]
            nx = x + dx[d]
            if 0 <= ny < N and 0 <= nx < N:
                if board[y][x] != board[ny][nx]:
                    board[y][x], board[ny][nx] = board[ny][nx], board[y][x]

                    for i in range(N):
                        for j in range(N):
                            max_candy_count = max(count_candy(i, j), max_candy_count)

                    board[ny][nx], board[y][x] = board[y][x], board[ny][nx]

print(max_candy_count)
