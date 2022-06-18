# (): 2
# []: 3
# (X): 2*X
# [X]: 3*X

stack = []
result = 0
is_correct_brackets = True
brackets = input()

value = 1
for index in range(len(brackets)):
    # 열린 괄호
    if brackets[index] == "(":
        value *= 2
        stack.append("(")
    elif brackets[index] == "[":
        value *= 3
        stack.append("[")
    # 닫힌 괄호
    elif brackets[index] == ")":
        if not stack or stack[-1] != "(":
            is_correct_brackets = False
            break
        stack.pop()
        if brackets[index - 1] == "(":
            result += value
        value //= 2

    elif brackets[index] == "]":
        if not stack or stack[-1] != "[":
            is_correct_brackets = False
            break
        stack.pop()
        if brackets[index - 1] == "[":
            result += value
        value //= 3

if stack:
    is_correct_brackets = False

if is_correct_brackets:
    print(result)
else:
    print(0)
