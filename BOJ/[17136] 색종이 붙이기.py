papers = []
for _ in range(10):
    row = list(map(int, input().split()))
    papers.append(row)

# 모든 1을 덮는데 필요한 색종이의 최소 개수를 출력한다.
# 1을 모두 덮는 것이 불가능한 경우에는 -1을 출력한다.

# 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며,
# 각 종류의 색종이는 5개씩 가지고 있다.
min_used_count = float("inf")


def is_done():
    for y in range(10):
        for x in range(10):
            if papers[y][x] == 1:
                return False
    return True


def is_coverable(y, x, size):  # 1 <= size <= 5
    if y + size - 1 >= 10 or x + size - 1 >= 10:
        return False

    for i in range(size):
        for j in range(size):
            ny = y + i
            nx = x + j
            if papers[ny][nx] == 0:
                return False
    return True


def cover(y, x, size):  # 1 <= size <= 5
    for i in range(size):
        for j in range(size):
            ny = y + i
            nx = x + j
            papers[ny][nx] = 0


def remove(y, x, size):  # 1 <= size <= 5
    for i in range(size):
        for j in range(size):
            ny = y + i
            nx = x + j
            papers[ny][nx] = 1


def dfs(used_count):
    if is_done():
        total = sum(used_count)
        global min_used_count
        min_used_count = min(total, min_used_count)
        return

    for y in range(10):
        for x in range(10):
            if papers[y][x] == 1:
                for size in range(5, 0, -1):
                    if used_count[size] < 5:
                        if is_coverable(y, x, size):
                            used_count[size] += 1
                            cover(y, x, size)

                            dfs(used_count)

                            used_count[size] -= 1
                            remove(y, x, size)
                return


dfs([0, 0, 0, 0, 0, 0])


if min_used_count != float("inf"):
    print(min_used_count)
else:
    print(-1)
