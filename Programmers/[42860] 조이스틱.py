result = []


def dfs(name, temp, visited, idx, cnt):

    # * Up + Down
    cnt += min(abs(ord(temp[idx]) - ord(name[idx])),
               ord("Z") - ord(name[idx]) + 1)
    temp = temp[:idx] + name[idx] + temp[idx+1:]

    # * is done?
    if name == temp:
        result.append(cnt)
        return

    # * Left
    n_idx = (idx - 1 + len(name)) % len(name)
    if not visited[idx][0]:
        visited[idx][0] = True
        dfs(name, temp, visited, n_idx, cnt+1)
        visited[idx][0] = False

    # * Right
    n_idx = (idx + 1) % len(name)
    if not visited[idx][1]:
        visited[idx][1] = True
        dfs(name, temp, visited, n_idx, cnt+1)
        visited[idx][1] = False


def solution(name):
    temp = 'A' * len(name)
    visited = visited = [[False] * 2 for _ in range(len(name))]
    dfs(name, temp, visited, 0, 0)

    return min(result)


"""
name = "JEROEN"
print(solution(name))
"""
