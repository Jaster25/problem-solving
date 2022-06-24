N = int(input())


def is_prime(number):
    for i in range(2, int(number ** 0.5) + 1):
        if number % i == 0:
            return False
    return True


def dfs(number):
    if 10 ** (N - 1) <= number:
        print(number)
        return

    for post_number in range(10):
        new_number = number * 10 + post_number
        if is_prime(new_number):
            dfs(new_number)


for prime in [2, 3, 5, 7]:
    dfs(prime)


# 에라토스테네스의 체: 시간 초과
"""
size = 10 ** N
is_prime = [False, False] + [True] * size


def is_amazing_prime(number):
    for i in range(1, N + 1):
        if not is_prime[int(str(number)[:i])]:
            return False
    return True


for number in range(2, int(size ** 0.5)):
    if is_prime[number]:
        index = 2
        while number * index < size:
            is_prime[number * index] = False
            index += 1

for number in range(size // 10, size):
    if is_amazing_prime(number):
        print(number)
"""
