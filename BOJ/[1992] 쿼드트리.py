import sys

# 1 <= N <= 64
N = int(sys.stdin.readline())
image = []
for _ in range(N):
    row = list(map(int, list(sys.stdin.readline().rstrip())))
    image.append(row)

result = ""


def quad_tree(y, x, n):
    global result
    standard = image[y][x]
    for i in range(y, y + n):
        for j in range(x, x + n):
            if standard != image[i][j]:
                gap = n // 2
                result += "("
                quad_tree(y, x, gap)
                quad_tree(y, x + gap, gap)
                quad_tree(y + gap, x, gap)
                quad_tree(y + gap, x + gap, gap)
                result += ")"
                return
    result += str(standard)


quad_tree(0, 0, N)
print(result)
