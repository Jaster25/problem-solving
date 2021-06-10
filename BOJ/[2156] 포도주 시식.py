from sys import stdin

N = int(stdin.readline())
wine = list((int(stdin.readline()) for _ in range(N)))
dp = [[0 for _ in range(3)] for _ in range(N + 1)]

if N == 1:
    print(wine[0])

else:
    # idx, consecutive count
    dp[1][0] = wine[0]
    dp[1][1] = wine[1]
    dp[1][2] = wine[0] + wine[1]

    for i in range(2, N):
        dp[i][0] = max(dp[i - 1][2], dp[i - 1][1], dp[i - 1][0])
        dp[i][1] = dp[i - 1][0] + wine[i]
        dp[i][2] = dp[i - 1][1] + wine[i]

    print(max(dp[N - 1]))
