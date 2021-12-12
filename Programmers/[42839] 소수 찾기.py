from itertools import permutations
import math

isPrime = []


def setSieveofEratosthenes(maxNumber):
    global isPrime
    # isPrime = [True for _ in range(maxNumber + 1)]
    # isPrime[0] = False
    # isPrime[1] = False
    isPrime = [False, False] + [True for _ in range(maxNumber)]

    for number in range(2, int(math.sqrt(maxNumber))):
        if isPrime[number]:
            count = 2
            while number * count <= maxNumber:
                isPrime[number * count] = False
                count += 1


def solution(numbers):
    numberSet = set()
    for size in range(1, len(numbers) + 1):
        for case in permutations(numbers, size):
            number = int("".join(map(str, case)))
            numberSet.add(number)

    setSieveofEratosthenes(max(numberSet))

    answer = 0
    for number in numberSet:
        if isPrime[number]:
            answer += 1
    return answer
