from collections import defaultdict

# info: 0: 양, 1: 늑대
# edge:[부모 노드 번호, 자식 노드 번호]

# 모은 양의 수보다 늑대의 수가 같거나 더 많아지면
# 바로 모든 양을 잡아먹어 버립니다

# info[0]의 값은 항상 0입니다.

max_sheep_count = 1
nodes = defaultdict(list)


def dfs(info, is_possible_paths, is_visited, sheep_count, wolf_count):
    global max_sheep_count
    max_sheep_count = max(sheep_count, max_sheep_count)

    # 우선 접근 가능한 모든 양 쪽으로 이동
    is_all_wolf = True
    for i in range(len(info)):
        if is_possible_paths[i]:
            if info[i] == 0:  # 양인지 확인
                is_all_wolf = False

                if is_visited[i]:
                    return
                is_visited[i] = True

                sheep_count += 1

                is_possible_paths[i] = False
                for path in nodes[i]:
                    if not is_visited[path]:
                        is_possible_paths[path] = True

    if not is_all_wolf:
        dfs(info, is_possible_paths[:], is_visited[:], sheep_count, wolf_count)
    else:  # 근처에 양이 없다면 늑대 쪽으로 이동
        if sheep_count <= wolf_count + 1:
            return
        for i in range(len(info)):
            if is_possible_paths[i]:
                original_paths = is_possible_paths[:]
                original_visited = is_visited[:]

                wolf_count += 1
                is_visited[i] = True
                is_possible_paths[i] = False
                for path in nodes[i]:
                    if not is_visited[path]:
                        is_possible_paths[path] = True

                dfs(info, is_possible_paths, is_visited, sheep_count, wolf_count)

                wolf_count -= 1
                is_visited[i] = False
                is_possible_paths = original_paths[:]
                is_visited = original_visited[:]


def solution(info, edges):
    for edge in edges:
        parent, child = edge
        nodes[parent].append(child)

    is_possible_paths = [False] * len(info)
    is_visited = [False] * len(info)

    is_possible_paths[0] = True
    dfs(info, is_possible_paths, is_visited, 0, 0)

    return max_sheep_count
