import sys

# 이분 탐색 풀이
N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
A.sort()

M = int(sys.stdin.readline())
B = list(map(int, sys.stdin.readline().split()))


def is_in(numbers, find_number):
    left = 0
    right = len(numbers) - 1
    while left <= right:
        mid = (left + right) // 2
        if numbers[mid] == find_number:
            return True

        if numbers[mid] < find_number:
            left = mid + 1
        else:
            right = mid - 1
    return False


for b in B:
    if is_in(A, b):
        print(1)
    else:
        print(0)

# 일반 풀이
# N = int(sys.stdin.readline())
# A = list(map(int, sys.stdin.readline().split()))

# M = int(sys.stdin.readline())
# B = list(map(int, sys.stdin.readline().split()))

# number_set = set()
# for a in A:
#     number_set.add(a)

# for b in B:
#     if b in number_set:
#         print(1)
#     else:
#         print(0)
