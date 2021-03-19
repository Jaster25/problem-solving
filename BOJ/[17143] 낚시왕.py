from collections import deque
from sys import stdin


class Shark:
    def __init__(self, y, x, s, d, z):
        self.y, self.x, self.s, self.d, self.z = y, x, s, d, z


fisherman_x = -1
answer = 0

R, C, M = map(int, stdin.readline().split())
sharks = deque()

for _ in range(M):
    r, c, s, d, z = map(int, stdin.readline().split())
    sharks.append(Shark(r - 1, c - 1, s, d, z))

dy = [0, -1, 1, 0, 0]
dx = [0, 0, 0, 1, -1]

while fisherman_x < C:
    # step1: move fisherman
    fisherman_x += 1

    # step2: remove shark
    nearest_shark_index = -1
    nearest_shark_y = float("inf")
    for i, shark in enumerate(sharks):
        if shark.x == fisherman_x:
            if shark.y < nearest_shark_y:
                nearest_shark_y = shark.y
                nearest_shark_index = i

    if nearest_shark_index != -1:
        answer += sharks[nearest_shark_index].z
        del sharks[nearest_shark_index]

    # step3: move sharks
    MAP = dict()
    shark_to_remove = []
    for shark in sharks:
        ny = shark.y + shark.s * dy[shark.d]
        nx = shark.x + shark.s * dx[shark.d]

        # 1: up, 2: down
        if shark.d == 1 or shark.d == 2:
            if not 0 <= ny < R:
                if ny < 0:
                    ny = abs(ny)
                if (ny // (R - 1)) % 2 == 0:
                    ny = ny % (R - 1)
                    shark.d = 2
                else:
                    ny = (R - 1) - (ny % (R - 1))
                    shark.d = 1

        # 3: right, 4: left
        else:
            if not 0 <= nx < C:
                if nx < 0:
                    nx = abs(nx)
                if (nx // (C - 1)) % 2 == 0:
                    nx = nx % (C - 1)
                    shark.d = 3
                else:
                    nx = (C - 1) - (nx % (C - 1))
                    shark.d = 4

        shark.y, shark.x = ny, nx

        # remove small shark in same location
        if (ny, nx) in MAP:
            located_shark = MAP[ny, nx]
            if located_shark.z > shark.z:
                shark_to_remove.append(shark)
            else:
                shark_to_remove.append(located_shark)
                MAP[ny, nx] = shark
        else:
            MAP[ny, nx] = shark

    for shark in shark_to_remove:
        sharks.remove(shark)

print(answer)