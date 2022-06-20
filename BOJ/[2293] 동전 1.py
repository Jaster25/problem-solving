import sys

n, k = map(int, sys.stdin.readline().split())
coins = []
for _ in range(n):
    coins.append(int(sys.stdin.readline()))

# 가치의 합이 k원인 동전 조합 구하기.
# 각각의 동전은 몇 개라도 사용할 수 있다.
dp = [1] + [0 for _ in range(k)]
for coin in coins:
    for i in range(1, k + 1):
        if i - coin >= 0:
            dp[i] += dp[i - coin]

print(dp[k])
