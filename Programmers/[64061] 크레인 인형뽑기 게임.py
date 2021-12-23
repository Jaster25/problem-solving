def find_doll(board, x):
    for y in range(0, len(board)):
        if board[y][x] != 0:
            return y
    return -1


def solution(board, moves):
    answer = 0
    stack = []
    for x in moves:
        doll_y = find_doll(board, x - 1)
        if doll_y != -1:
            doll = board[doll_y][x - 1]
            if len(stack) != 0 and stack[-1] == doll:
                stack.pop()
                answer += 2
            else:
                stack.append(doll)
            board[doll_y][x - 1] = 0
    return answer
