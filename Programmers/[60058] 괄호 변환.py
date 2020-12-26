def findBalancedIdx(U):
    idx_balanced = 0
    for idx, val in enumerate(U):
        if val == '(':
            idx_balanced += 1
        else:
            idx_balanced -= 1

        if idx_balanced == 0:
            return idx


def isCorrect(U):
    stack = []
    for val in U:
        if val == '(':
            stack.append(val)
        else:
            if len(stack) == 0:
                return False
            stack.pop()

    if len(stack) == 0:
        return True
    return False


def solution(p):
    # * 1
    if p == "" or isCorrect(p):
        return p

    # * 2
    u = p[: findBalancedIdx(p) + 1]
    v = p[findBalancedIdx(p) + 1:]

    # * 3
    if isCorrect(u):
        return u + solution(v)

    # * 4
    else:
        temp = "(" + solution(v) + ")"

        for i in u[1:-1]:
            if i == '(':
                temp += ')'
            else:
                temp += '('
    return temp
