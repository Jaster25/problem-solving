answer = []


def dfs(number, start, bridge, goal):
    if number > 1:
        dfs(number - 1, start, goal, bridge)
        answer.append([start, goal])
        dfs(number - 1, bridge, start, goal)
    elif number == 1:
        answer.append([start, goal])


def solution(n):
    dfs(n, 1, 2, 3)
    return answer
