import sys
from itertools import combinations

# (1 ≤ N ≤ 20, |S| ≤ 1,000,000)
N, S = map(int, sys.stdin.readline().split())
sequence = list(map(int, sys.stdin.readline().split()))

count = 0
for size in range(1, len(sequence) + 1):
    for case in combinations(sequence, size):
        if sum(case) == S:
            count += 1

print(count)
