# LCS(Longest Common Subsequence, 최장 공통 부분 수열)
# 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

# 최대 1000글자
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
            lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j])

print(lcs[i + 1][j + 1])
