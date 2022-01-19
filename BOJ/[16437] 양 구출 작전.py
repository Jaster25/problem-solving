import sys

sys.setrecursionlimit(100000)

# 각 섬에서 1번 섬으로 가는 경로는 유일
# N (2 ≤ N ≤ 123,456)
N = int(sys.stdin.readline())
graph = [[0, []] for _ in range(N + 1)]

for i in range(2, N + 1):
    type, count, island = sys.stdin.readline().split()
    if type == "W":  # 늑대
        count = -int(count)
    else:
        count = int(count)
    graph[i][0] = count
    graph[int(island)][1].append(i)


def dfs(i):
    answer = graph[i][0]
    for node in graph[i][1]:
        answer += dfs(node)

    if answer < 0:
        return 0
    else:
        return answer


print(dfs(1))
