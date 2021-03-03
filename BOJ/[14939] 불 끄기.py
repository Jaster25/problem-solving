from sys import stdin
import math

global min_cnt
min_cnt = float("inf")
bulb = [list(map(lambda x: True if x == "O" else False, list(stdin.readline().strip()))) for _ in range(10)]


def toggle_light(y, x):
    dy = [-1, 0, 1, 0, 0]
    dx = [0, -1, 0, 1, 0]
    for i in range(5):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < 10 and 0 <= nx < 10:
            temp[ny][nx] = not temp[ny][nx]


for num in range(1024):
    temp = list(map(lambda x: x[:], bulb))

    cnt = 0
    bit = ("000000000" + str(bin(num)[2:]))[-10:]
    for i in range(10):
        if bit[i] == "1":
            toggle_light(0, i)
            cnt += 1

    for i in range(1, 10):
        for j in range(10):
            if temp[i - 1][j]:
                toggle_light(i, j)
                cnt += 1

    if True not in temp[9]:
        min_cnt = min(min_cnt, cnt)

print(-1 if math.isinf(min_cnt) else min_cnt)