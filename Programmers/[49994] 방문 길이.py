def solution(dirs):
    answer = 0
    y, x = 5, 5
    visited = [[[False for col in range(11)]
                for row in range(11)] for depth in range(4)]

    dir_ = {'U': 0, 'R': 1, 'D': 2, 'L': 3}
    dy, dx = [-1, 0, 1,  0], [0, 1, 0,  -1]

    while dirs:
        dir = dirs[0]
        dirs = dirs[1:]
        ny, nx = y + dy[dir_[dir]], x + dx[dir_[dir]]
        if 0 <= ny <= 10 and 0 <= nx <= 10:
            if not visited[dir_[dir]][y][x]:
                answer += 1
                visited[dir_[dir]][y][x] = True
                visited[(dir_[dir] + 2) % 4][ny][nx] = True
            y, x = ny, nx
    return answer


if __name__ == "__main__":
    # dirs = "ULURRDLLU"
    dirs = "LULLLLLLU"
    print(solution(dirs))
