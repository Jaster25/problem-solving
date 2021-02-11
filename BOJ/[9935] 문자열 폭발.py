from sys import stdin


def solution():
    s = stdin.readline().strip()
    bomb = stdin.readline().strip()
    bomb_last = bomb[-1]
    bomb_len = len(bomb)

    stack = []
    for ch in s:
        stack.append(ch)
        if ch == bomb_last and len(stack) >= bomb_len:
            temp = []
            for i in range(bomb_len):
                popped = stack.pop()
                temp.append(popped)
                if popped != bomb[-1 - i]:
                    while temp:
                        stack.append(temp.pop())
                    break

    if stack:
        print("".join(stack))
    else:
        print("FRULA")


solution()