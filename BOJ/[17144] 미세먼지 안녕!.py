from sys import stdin


room = []
R, C, T = list(map(int, stdin.readline().split()))
for _ in range(R):
    room.append(list(map(int, stdin.readline().split())))

for i in range(R):
    if room[i][0] == -1:
        cleaner_top = i
        cleaner_bottom = i + 1
        break

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def spread_dust():
    temp = [[0 for _ in range(C)] for _ in range(R)]
    Q = []
    for i in range(R):
        for j in range(C):
            if room[i][j] >= 5:
                Q.append([i, j])

    while Q:
        y, x = Q.pop()
        cnt = 0
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < R and 0 <= nx < C:
                if room[ny][nx] != -1:
                    cnt += 1
                    temp[ny][nx] += int(room[y][x] / 5)
        temp[y][x] -= cnt * int(room[y][x] / 5)

    # room += temp
    for i in range(R):
        for j in range(C):
            room[i][j] += temp[i][j]


def cleaner_operation():
    # cleaner_top
    temp = 0

    # right
    i = 1
    while i < C:
        room[cleaner_top][i], temp = temp, room[cleaner_top][i]
        i += 1
    # up
    i = cleaner_top - 1
    while i >= 0:
        room[i][C - 1], temp = temp, room[i][C - 1]
        i -= 1
    # left
    i = C - 2
    while i >= 0:
        room[0][i], temp = temp, room[0][i]
        i -= 1
    # down
    i = 1
    while i < cleaner_top:
        room[i][0], temp = temp, room[i][0]
        i += 1

    # cleaner_botoom
    temp = 0

    # right
    i = 1
    while i < C:
        room[cleaner_bottom][i], temp = temp, room[cleaner_bottom][i]
        i += 1
    # down
    i = cleaner_bottom + 1
    while i < R:
        room[i][C - 1], temp = temp, room[i][C - 1]
        i += 1
    # left
    i = C - 2
    while i >= 0:
        room[R - 1][i], temp = temp, room[R - 1][i]
        i -= 1
    # up
    i = R - 2
    while i > cleaner_bottom:
        room[i][0], temp = temp, room[i][0]
        i -= 1


def count_dust():
    cnt = 0
    for i in range(R):
        for j in range(C):
            if room[i][j] != -1:
                cnt += room[i][j]
    return cnt


while T:
    T -= 1
    spread_dust()
    cleaner_operation()

print(count_dust())