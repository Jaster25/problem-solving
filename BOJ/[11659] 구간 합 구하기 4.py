from sys import stdin

N, M = map(int, stdin.readline().split())

ar_sum = [0] * (N)
ar = list(map(int, stdin.readline().split()))

ar_sum[0] = ar[0]
for i in range(1, N):
    ar_sum[i] = ar_sum[i - 1] + ar[i]

for _ in range(M):
    a, b = list(map(int, stdin.readline().split()))
    print(ar_sum[b - 1] - ar_sum[a - 2] if a - 2 >= 0 else ar_sum[b - 1])
