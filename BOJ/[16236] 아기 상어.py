from collections import deque
from sys import stdin

MAP = []
N = int(stdin.readline())
for i in range(N):
    row = list(map(int, stdin.readline().split()))
    MAP.append(row)


class Shark:
    def __init__(self):
        self.y = None
        self.x = None
        self.size = 2
        self.exp = 0
        self.time = 0

    def set_position(self, y, x):
        self.y = y
        self.x = x

    def size_up(self):
        self.size += 1
        self.exp = 0

    def find_fish(self):
        visited = [[False] * N for _ in range(N)]
        dy = [-1, 0, 0, 1]
        dx = [0, -1, 1, 0]

        Q = deque()
        eatable = []
        Q.append([0, self.y, self.x])
        visited[self.y][self.x] = True

        while Q:
            dist, y, x = Q.popleft()
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                ndist = dist + 1
                if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx]:
                    if not MAP[ny][nx]:
                        Q.append([ndist, ny, nx])
                        visited[ny][nx] = True
                    else:
                        if self.size > MAP[ny][nx]:
                            if not len(eatable):
                                eatable.append([ndist, [ny, nx]])
                            elif min(eatable)[0] >= ndist:
                                eatable.append([ndist, [ny, nx]])
                        elif self.size == MAP[ny][nx]:
                            Q.append([ndist, ny, nx])
                            visited[ny][nx] = True

        if len(eatable) == 0:
            return None

        min_dist = min(eatable)[0]
        fy = fx = 1000
        for fish in eatable:
            if min_dist == fish[0]:
                if fy > fish[1][0]:
                    fy = fish[1][0]
                    fx = fish[1][1]
                elif fy == fish[1][0] and fx > fish[1][1]:
                    fy = fish[1][0]
                    fx = fish[1][1]
        return [min_dist, fy, fx]

    def eat(self, dist, y, x):
        MAP[self.y][self.x] = 0
        MAP[y][x] = 9
        self.y = y
        self.x = x
        self.time += dist
        self.exp += 1


def solution():
    shark = Shark()

    for i in range(N):
        for j in range(N):
            if MAP[i][j] == 9:
                shark.set_position(i, j)

    while True:
        fish = shark.find_fish()
        if not fish:
            break

        shark.eat(fish[0], fish[1], fish[2])
        if shark.exp == shark.size:
            shark.size_up()

    print(shark.time)


solution()
