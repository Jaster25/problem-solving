s1 = input()
s2 = input()

matrix = [[0 for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]

for i in range(len(s1)):
    for j in range(len(s2)):
        if s1[i] == s2[j]:
            matrix[i + 1][j + 1] = matrix[i][j] + 1
        else:
            matrix[i + 1][j + 1] = max(matrix[i + 1][j], matrix[i][j + 1])

print(matrix[-1][-1])
