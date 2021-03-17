from sys import stdin


N = int(input())
points = [list(map(int, stdin.readline().split())) for _ in range(N)]
points.append(points[0])

sum = 0
for i in range(N):
    sum += points[i][0] * points[i + 1][1]
    sum -= points[i + 1][0] * points[i][1]
sum /= 2

print(round(abs(sum), 1))
