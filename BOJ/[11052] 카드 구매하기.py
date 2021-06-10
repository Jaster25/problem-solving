from sys import stdin

N = int(stdin.readline())
cost = list(map(int, stdin.readline().split()))
cost.insert(0, 0)

dp = [0 for _ in range(N + 1)]
dp[1] = cost[1]
dp[2] = max(cost[1] * 2, cost[2])

for i in range(3, N + 1):
    dp[i] = cost[i]
    for j in range(1, i // 2 + 1):
        dp[i] = max(dp[i], dp[i - j] + dp[j])

print(dp[N])
