from sys import stdin
from collections import deque
import re


def solution():
    s = stdin.readline()
    # s = "55-50+40"

    operand = deque(list(map(int, re.split('\-|\+', s))))
    operator = deque()
    for ch in s:
        if ch == '-' or ch == '+':
            operator.append(ch)

    while '+' in operator:
        idx = operator.index('+')
        operand[idx] += operand[idx+1]
        del operator[idx]
        del operand[idx+1]

    while operator:
        operator.popleft()
        operand[1] = operand[0] - operand[1]
        operand.popleft()

    print(operand.pop())


solution()
