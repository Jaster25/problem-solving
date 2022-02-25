import sys

# (2 <= V <= 400, 0 <= E <= V(V-1))
V, E = map(int, sys.stdin.readline().split())
distances = [[float("inf")] * (V + 1) for _ in range((V + 1))]
for _ in range(E):
    a, b, c = map(int, sys.stdin.readline().split())
    distances[a][b] = c

for k in range(1, V + 1):
    for i in range(1, V + 1):
        for j in range(1, V + 1):
            if distances[i][j] > distances[i][k] + distances[k][j]:
                distances[i][j] = distances[i][k] + distances[k][j]

minimum_distance = float("inf")
for i in range(1, V + 1):
    minimum_distance = min(minimum_distance, distances[i][i])

if minimum_distance == float("inf"):
    print(-1)
else:
    print(minimum_distance)
