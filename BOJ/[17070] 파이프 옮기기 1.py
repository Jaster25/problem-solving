import sys

# 파이썬 DFS 풀이로는 시간 초과가 발생하여 DP 풀이로 수정


# N(3 ≤ N ≤ 16)
N = int(sys.stdin.readline())

# 빈 칸은 0, 벽은 1로 주어진다. (1, 1)과 (1, 2)는 항상 빈 칸이다.
house = []
for _ in range(N):
    house.append(list(map(int, sys.stdin.readline().split())))

# dp[y][x][이전 방향]
# 이전 방향 -> 0: 가로, 1: 세로, 2: 대각선
dp = [[[0] * 3 for _ in range(N)] for _ in range(N)]
for x in range(1, N):
    if house[0][x] == 1:
        break
    dp[0][x][0] = 1

for y in range(1, N):
    for x in range(1, N):
        if house[y][x] == 1:
            continue

        #  d: 0
        dp[y][x][0] = dp[y][x - 1][0] + dp[y][x - 1][2]
        #  d: 1
        dp[y][x][1] = dp[y - 1][x][1] + dp[y - 1][x][2]
        #  d: 2
        if house[y - 1][x] == 0 and house[y][x - 1] == 0:
            dp[y][x][2] = sum(dp[y - 1][x - 1])

print(sum(dp[N - 1][N - 1]))


# -------------시간 초과 코드-------------

# # N(3 ≤ N ≤ 16)
# N = int(sys.stdin.readline())

# # 빈 칸은 0, 벽은 1로 주어진다. (1, 1)과 (1, 2)는 항상 빈 칸이다.
# house = []
# for _ in range(N):
#     house.append(list(map(int, sys.stdin.readline().split())))

# answer = 0


# def dfs(y, x, d):
#     if y == N - 1 and x == N - 1:
#         global answer
#         answer += 1
#         return

#     # 가로
#     if d in [0, 2]:
#         if x + 1 < N:
#             if house[y][x + 1] == 0:
#                 dfs(y, x + 1, 0)
#     # 세로
#     if d in [1, 2]:
#         if y + 1 < N:
#             if house[y + 1][x] == 0:
#                 dfs(y + 1, x, 1)
#     # 대각선
#     if x + 1 < N and y + 1 < N:
#         if house[y][x + 1] == 0 and house[y + 1][x] == 0 and house[y + 1][x + 1] == 0:
#             dfs(y + 1, x + 1, 2)


# dfs(0, 1, 0)

# print(answer)
