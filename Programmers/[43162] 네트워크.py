def solution(n, computers):
    answer = 0
    visited = [False for _ in range(n)]

    def dfs(computer):
        for i in range(n):
            if computers[computer][i]:
                if not visited[i]:
                    visited[i] = True
                    dfs(i)

    for i in range(n):
        if not visited[i]:
            visited[i] = True
            answer += 1
            dfs(i)

    return answer


if __name__ == "__main__":
    # n, computers = 3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
    n, computers = 3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]
    # n, computers = 3, [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    print(solution(n, computers))
