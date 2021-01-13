def solution(m, n, board):
    MAP, to_remove = [[0] * m for _ in range(n)], set()

    # * rotate 90'
    for i in range(n):
        for j in range(m):
            MAP[i][j] = board[m-1-j][i]

    def search():
        for y in range(n-1):
            for x in range(m-1):
                if MAP[y][x] == MAP[y+1][x] == MAP[y][x+1] == MAP[y+1][x+1] != ' ':
                    to_remove.update([(y, x), (y+1, x), (y, x+1), (y+1, x+1)])

    search()
    while to_remove:
        # * remove the blocks
        while to_remove:
            y, x = to_remove.pop()
            MAP[y][x] = ' '

        # * trim
        for idx, row in enumerate(MAP):
            row_str = "".join(row).replace(' ', '')
            row_str += ' ' * (m - len(row_str))
            MAP[idx] = list(row_str)

        search()

    return sum(map(lambda x: x.count(' '), MAP))


if __name__ == "__main__":
    m, n, board = 4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]
    # m, n, board = 6, 6, ["TTTANT", "RRFACC",
    #                      "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]
    print(solution(m, n, board))
