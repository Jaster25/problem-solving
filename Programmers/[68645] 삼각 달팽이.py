import itertools


def solution(n):
    MAP = [[0] * i for i in range(1, n+1)]
    num = 1
    y = -1
    x = 0

# * 0: down, 1: right, 2: left + up
    dy = [1, 0, -1]
    dx = [0, 1, -1]
    d_cur = 0

    def isDone():
        for m in MAP:
            if 0 in m:
                return False
        return True

    while not isDone():
        while 1:
            ny = y+dy[d_cur]
            nx = x+dx[d_cur]

            if ny < 0 or ny > n-1 or nx < 0 or nx > n-1 or ny < nx or MAP[ny][nx] != 0:
                break

            MAP[ny][nx] = num
            y = ny
            x = nx
            num += 1
        d_cur = (d_cur+1) % 3

    answer = list(itertools.chain(*MAP))
    return answer
