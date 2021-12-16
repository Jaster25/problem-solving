from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs(place, y, x):
    isVisited = [[-1] * 5 for _ in range(5)]
    isVisited[y][x] = 0
    queue = deque([[y, x]])
    while queue:
        [y, x] = queue.popleft()
        if isVisited[y][x] != 0 and place[y][x] == "P":
            return False  # 거리두기 지키지 않는 경우
        if isVisited[y][x] == 2:
            continue
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < 5 and 0 <= nx < 5:
                if isVisited[ny][nx] == -1 and place[ny][nx] != "X":
                    isVisited[ny][nx] = isVisited[y][x] + 1
                    queue.append([ny, nx])
    return True


def isFollowingRule(place):
    for i in range(5):
        for j in range(5):
            if place[i][j] == "P":
                if not bfs(place, i, j):
                    return False
    return True


def solution(places):
    answer = []
    for place in places:
        if isFollowingRule(place):
            answer.append(1)
        else:
            answer.append(0)
    return answer
