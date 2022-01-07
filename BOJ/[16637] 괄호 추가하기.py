# 1 ≤ N ≤ 19
# 항상 올바른 수식, 연산자는 +, -, * 중 하나
# 정답은 231보다 작고, -231보다 크다

# 중첩된 괄호 X
# 괄호 안에는 연산자 단 하나
# index 홀수: 숫자, 짝수: 기호
N = int(input())
expression = input()
max_result = float("-inf")


def dfs(value, start_index):
    if start_index >= len(expression):
        global max_result
        max_result = max(value, max_result)
        return

    new_value = int(expression[start_index + 1])

    if expression[start_index] == "+":
        dfs(value + new_value, start_index + 2)
    elif expression[start_index] == "-":
        dfs(value - new_value, start_index + 2)
    elif expression[start_index] == "*":
        dfs(value * new_value, start_index + 2)

    if start_index + 2 < len(expression):
        if expression[start_index + 2] == "+":
            new_value += int(expression[start_index + 3])
        elif expression[start_index + 2] == "-":
            new_value -= int(expression[start_index + 3])
        elif expression[start_index + 2] == "*":
            new_value *= int(expression[start_index + 3])

        if expression[start_index] == "+":
            dfs(value + new_value, start_index + 4)
        elif expression[start_index] == "-":
            dfs(value - new_value, start_index + 4)
        elif expression[start_index] == "*":
            dfs(value * new_value, start_index + 4)


dfs(int(expression[0]), 1)

print(max_result)
