from sys import stdin

N = int(stdin.readline())


def solution():
    sum = 0
    for i in range(1, N+1):
        sum += i * (N // i)
    print(sum)


solution()
