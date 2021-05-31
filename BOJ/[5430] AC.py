from sys import stdin


def solution(p, n, arr):
    isReversed = False
    leftIdx = 0
    rightIdx = n

    for order in p:
        if order == "R":
            isReversed = not isReversed
        else:
            if isReversed:
                rightIdx -= 1
            else:
                leftIdx += 1
            if leftIdx > rightIdx:
                return "error"

    if isReversed:
        return list(reversed(arr[leftIdx:rightIdx]))
    else:
        return arr[leftIdx:rightIdx]


T = int(stdin.readline())
while T:
    p = stdin.readline().strip()
    n = int(stdin.readline())
    arr = []
    arrStdin = stdin.readline().strip()[1:-1]
    if arrStdin:
        arr = list(map(int, arrStdin.split(",")))

    result = solution(p, n, arr)

    if result == "error":
        print("error")
    else:
        print(str(result).replace(" ", ""))

    T -= 1
