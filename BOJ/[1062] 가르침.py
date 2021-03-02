from sys import stdin
from collections import deque

global max_cnt
max_cnt = 0

N, K = list(map(int, input().split()))
voca_list = [set(stdin.readline().strip()) for _ in range(N)]
teach = [False for _ in range(26)]

for ch in ["a", "c", "t", "i", "n"]:
    teach[ord(ch) - ord("a")] = True


def dfs(next_index, teach_cnt):
    if teach_cnt == K:
        cnt = 0
        for voca in voca_list:
            for ch in voca:
                if not teach[ord(ch) - ord("a")]:
                    break
            else:
                cnt += 1

        global max_cnt
        max_cnt = max(max_cnt, cnt)
    else:
        for i in range(next_index, 26):
            if not teach[i]:
                teach[i] = True
                dfs(i + 1, teach_cnt + 1)
                teach[i] = False


if K < 5:
    print(0)
elif K == 26:
    print(N)
else:
    dfs(0, 5)
    print(max_cnt)