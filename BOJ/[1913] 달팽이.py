N = int(input())
find_number = int(input())

matrix = [[0] * N for _ in range(N)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

number = N * N
dir = 2
y = 0
x = 0

matrix[0][0] = number
number -= 1
while number > 0:
    ny = y + dy[dir]
    nx = x + dx[dir]
    if 0 <= ny < N and 0 <= nx < N and matrix[ny][nx] == 0:
        matrix[ny][nx] = number
        number -= 1
        y = ny
        x = nx
    else:
        dir = (dir + 4 - 1) % 4

for i in range(N):
    for j in range(N):
        print(matrix[i][j], end=" ")
    print()

for i in range(N):
    for j in range(N):
        if matrix[i][j] == find_number:
            print(i + 1, j + 1)
