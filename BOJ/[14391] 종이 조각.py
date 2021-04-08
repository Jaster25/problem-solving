from collections import deque
from sys import stdin

N, M = map(int, stdin.readline().split())
paper = [list(map(int, stdin.readline().rstrip())) for _ in range(N)]
result = 0

for bit in range(1 << N * M):
    total = 0

    # 가로 방향: bit == 1
    for i in range(N):
        piece = 0
        for j in range(M):
            index = i * M + j
            if bit & (1 << index) != 0:
                piece = piece * 10 + paper[i][j]
            else:
                total += piece
                piece = 0
        total += piece

    # 세로 방향: bit == 0
    for j in range(M):
        piece = 0
        for i in range(N):
            index = i * M + j
            if bit & (1 << index) != 0:
                total += piece
                piece = 0
            else:
                piece = piece * 10 + paper[i][j]
        total += piece

    result = max(result, total)
print(result)
