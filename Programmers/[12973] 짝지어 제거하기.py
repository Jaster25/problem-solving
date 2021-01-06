def solution(S):
    stack = []
    for s in S:
        if not stack:
            stack.append(s)
        else:
            top = stack.pop()
            if top != s:
                stack.append(top)
                stack.append(s)

    if stack:
        return 0
    return 1


if __name__ == '__main__':
    s = "cdcd"
    print(solution(s))
