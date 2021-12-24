str1 = input()
str2 = input()
str1_length = len(str1)
str2_length = len(str2)

lcs = [[0] * (str2_length + 1) for _ in range(str1_length + 1)]
for i in range(str1_length):
    for j in range(str2_length):
        if str1[i] == str2[j]:
            lcs[i + 1][j + 1] = lcs[i][j] + 1
        else:
            lcs[i + 1][j + 1] = max(lcs[i + 1][j], lcs[i][j + 1])

stack = []
y, x = str1_length, str2_length
while lcs[y][x] > 0:
    # 위쪽 혹은 왼쪽에 같은 LCS가 있으면 이동
    if lcs[y][x] == lcs[y - 1][x]:
        y -= 1
    elif lcs[y][x] == lcs[y][x - 1]:
        x -= 1
    # 같은 LCS가 없으면, 스택에 해당 문자 추가 후 대각선으로 이동
    else:
        stack.append(str1[y - 1])
        y -= 1
        x -= 1

max_length = lcs[str1_length][str2_length]
lcs_str = "".join(reversed(stack))

print(max_length)
print(lcs_str)
