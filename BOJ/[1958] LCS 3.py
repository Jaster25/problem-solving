str1 = input()
str2 = input()
str3 = input()
str1_length = len(str1)
str2_length = len(str2)
str3_length = len(str3)

lcs = [[[0] * (str3_length + 1) for _ in range(str2_length + 1)] for _ in range(str1_length + 1)]
for i in range(str1_length):
    for j in range(str2_length):
        for k in range(str3_length):
            if str1[i] == str2[j] == str3[k]:
                lcs[i + 1][j + 1][k + 1] = lcs[i][j][k] + 1
            else:
                lcs[i + 1][j + 1][k + 1] = max(lcs[i + 1][j + 1][k], lcs[i + 1][j][k + 1], lcs[i][j + 1][k + 1])

print(lcs[i + 1][j + 1][k + 1])
