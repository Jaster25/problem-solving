from itertools import permutations
import re


def priority():
    return list(permutations(['+', '-', '*'], 3))


def cal(operand, operator, sign):
    idx = operator.index(sign)
    if sign == '+':
        operand[idx] = operand[idx] + operand[idx+1]
    elif sign == '-':
        operand[idx] = operand[idx] - operand[idx+1]
    else:
        operand[idx] = operand[idx] * operand[idx+1]
    del operator[idx]
    del operand[idx+1]


def solution(s):

    result = []

    for p in priority():
        operand = list(map(int, re.split('\+|\-|\*', s)))
        operator = []
        for ch in s:
            if ch == '+' or ch == '-' or ch == '*':
                operator.append(ch)

        while p[0] in operator:
            cal(operand, operator, p[0])
        while p[1] in operator:
            cal(operand, operator, p[1])
        while p[2] in operator:
            cal(operand, operator, p[2])

        result.append(abs(operand[0]))

    return(max(result))


"""
s = "100-200*300-500+20"
print(solution(s))
"""
