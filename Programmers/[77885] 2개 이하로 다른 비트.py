def findNextMinNumber(number):
    if number % 2 == 0:
        return number + 1

    numberBin = list("0" + bin(number)[2:])

    zeroIndex = "".join(numberBin).rfind("0")
    numberBin[zeroIndex] = "1"
    numberBin[zeroIndex + 1] = "0"
    return int("".join(numberBin), 2)


def solution(numbers):
    answer = []
    for number in numbers:
        answer.append(findNextMinNumber(number))
    return answer
