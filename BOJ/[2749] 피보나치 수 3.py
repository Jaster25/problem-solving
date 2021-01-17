
# * Pisano Period 피사노 주기

n = int(input())

done = False
dp = [0, 1, 1]

for i in range(3, n+1):
    dp.append((dp[i-1] + dp[i-2]) % 1000000)
    if dp[-2] == 0 and dp[-1] == 1:
        dp.pop()
        dp.pop()
        break
else:
    done = True
    print(dp[n])

if not done:
    print(dp[n % len(dp)])
