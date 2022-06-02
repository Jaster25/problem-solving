import sys

N = int(sys.stdin.readline())
costs = []
for i in range(N):
    costs.append(list(map(int, sys.stdin.readline().split())))

min_cost = float("INF")

# 시작과 끝 색 비교를 위해 고정해놓고 시작
for start_color in range(3):
    dp = [[float("INF")] * 3 for _ in range(N)]
    dp[0][start_color] = costs[0][start_color]

    for i in range(1, N):
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0]
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1]
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2]

    for last_color in range(3):
        if last_color != start_color:
            min_cost = min(dp[N - 1][last_color], min_cost)

print(min_cost)
