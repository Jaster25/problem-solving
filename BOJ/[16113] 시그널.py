import sys

N = int(sys.stdin.readline())
signal = sys.stdin.readline()

len_signal = N // 5
signal = [signal[i : i + len_signal] for i in range(0, N, len_signal)]


numbers = {
    0: [
        ["#", "#", "#"],
        ["#", ".", "#"],
        ["#", ".", "#"],
        ["#", ".", "#"],
        ["#", "#", "#"],
    ],
    1: [
        ["#"],
        ["#"],
        ["#"],
        ["#"],
        ["#"],
    ],
    2: [
        ["#", "#", "#"],
        [".", ".", "#"],
        ["#", "#", "#"],
        ["#", ".", "."],
        ["#", "#", "#"],
    ],
    3: [
        ["#", "#", "#"],
        [".", ".", "#"],
        ["#", "#", "#"],
        [".", ".", "#"],
        ["#", "#", "#"],
    ],
    4: [
        ["#", ".", "#"],
        ["#", ".", "#"],
        ["#", "#", "#"],
        [".", ".", "#"],
        [".", ".", "#"],
    ],
    5: [
        ["#", "#", "#"],
        ["#", ".", "."],
        ["#", "#", "#"],
        [".", ".", "#"],
        ["#", "#", "#"],
    ],
    6: [
        ["#", "#", "#"],
        ["#", ".", "."],
        ["#", "#", "#"],
        ["#", ".", "#"],
        ["#", "#", "#"],
    ],
    7: [
        ["#", "#", "#"],
        [".", ".", "#"],
        [".", ".", "#"],
        [".", ".", "#"],
        [".", ".", "#"],
    ],
    8: [
        ["#", "#", "#"],
        ["#", ".", "#"],
        ["#", "#", "#"],
        ["#", ".", "#"],
        ["#", "#", "#"],
    ],
    9: [
        ["#", "#", "#"],
        ["#", ".", "#"],
        ["#", "#", "#"],
        [".", ".", "#"],
        ["#", "#", "#"],
    ],
}


def is_same_number(start_index, number):
    for y in range(0, 5):
        for x in range(0, 1 if number == 1 else 3):
            if signal[y][start_index + x] != numbers[number][y][x]:
                return False
    return True


def decode(start_index: int):
    if start_index + 2 >= len_signal:
        return 1

    for number in [0, 2, 3, 4, 5, 6, 7, 8, 9, 1]:
        if is_same_number(start_index, number):
            return number


result = ""
index = 0
while index < len_signal:
    if signal[0][index] == "#":
        decoded_number = decode(index)
        result += str(decoded_number)
        if decoded_number == 1:
            index += 2
        else:
            index += 4
    else:
        index += 1

print(result)
