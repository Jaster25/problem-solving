max_count = 0
is_visited = []

# 현재 피로도, 던전 정보, 돌은 던전 수
def dfs(current_cost, dungeons, count):
    global max_count
    max_count = max(count, max_count)

    for index in range(len(dungeons)):
        if not is_visited[index]:
            min_cost, cost = dungeons[index]

            if current_cost >= min_cost:
                is_visited[index] = True
                dfs(current_cost - cost, dungeons, count + 1)
                is_visited[index] = False


def solution(k, dungeons):
    global is_visited
    is_visited = [False for _ in range(len(dungeons))]

    dfs(k, dungeons, 0)

    return max_count
