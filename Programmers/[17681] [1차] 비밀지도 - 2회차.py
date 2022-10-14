def convert_to_binary(n, number):
    string = "0" * n + str(bin(number)[2:])
    string = string[len(string) - n :]
    return string


def overlap(n, row1, row2):
    new_row = ""
    for i in range(n):
        if row1[i] == "1" or row2[i] == "1":
            new_row += "1"
        else:
            new_row += "0"
    return new_row


def convert_to_map(n, row):
    key = ""
    for i in range(n):
        if row[i] == "1":
            key += "#"
        else:
            key += " "
    return key


def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        row1_binary = convert_to_binary(n, arr1[i])
        row2_binary = convert_to_binary(n, arr2[i])
        key_binary = overlap(n, row1_binary, row2_binary)
        key = convert_to_map(n, key_binary)
        answer.append(key)
    return answer
