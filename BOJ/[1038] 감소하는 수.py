from itertools import combinations

N = int(input())

numbers = []
for size in range(1, 11):  # 1 ~ 9876543210
    for case in combinations([i for i in range(0, 10)], size):
        number = int("".join(map(str, sorted(case, reverse=True))))
        numbers.append(number)

numbers.sort()

if len(numbers) >= N + 1:
    print(numbers[N])
else:
    print(-1)
