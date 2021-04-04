N = int(input())
dp_cnt = [float("inf") for _ in range(N + 1)]
dp_path = [[] for _ in range(N + 1)]

dp_cnt[1] = 0
dp_path[1] = [1]

for i in range(2, N + 1):
    if i % 3 == 0:
        if dp_cnt[i] > dp_cnt[i // 3] + 1:
            dp_cnt[i] = dp_cnt[i // 3] + 1
            dp_path[i] = dp_path[i // 3] + [i]
    if i % 2 == 0:
        if dp_cnt[i] > dp_cnt[i // 2] + 1:
            dp_cnt[i] = dp_cnt[i // 2] + 1
            dp_path[i] = dp_path[i // 2] + [i]
    if i > 1:
        if dp_cnt[i] > dp_cnt[i - 1] + 1:
            dp_cnt[i] = dp_cnt[i - 1] + 1
            dp_path[i] = dp_path[i - 1] + [i]

print(dp_cnt[N])
for i in dp_path[N][::-1]:
    print(i, end=" ")
