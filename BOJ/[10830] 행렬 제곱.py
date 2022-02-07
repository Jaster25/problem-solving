import sys

N, B = map(int, sys.stdin.readline().split())
matrix = []
for i in range(N):
    row = list(map(int, sys.stdin.readline().split()))
    matrix.append(row)


def multiply_matrix(matrix1, matrix2):
    matrix_len = len(matrix1)
    multiplied_matrix = [[0] * matrix_len for _ in range(matrix_len)]
    for i in range(matrix_len):
        for j in range(matrix_len):
            for k in range(matrix_len):
                multiplied_matrix[i][j] += matrix1[i][k] * matrix2[k][j]
            multiplied_matrix[i][j] %= 1000
    return multiplied_matrix


def divide_conquer(matrix, count):
    if count == 1:
        matrix_len = len(matrix)
        for i in range(matrix_len):
            for j in range(matrix_len):
                matrix[i][j] %= 1000
        return matrix

    multiplied_matrix = divide_conquer(matrix, count // 2)
    if count % 2 == 0:
        return multiply_matrix(multiplied_matrix, multiplied_matrix)
    else:
        return multiply_matrix(multiply_matrix(multiplied_matrix, multiplied_matrix), matrix)


answer = divide_conquer(matrix, B)
for row in answer:
    for number in row:
        print(number, end=" ")
    print()
