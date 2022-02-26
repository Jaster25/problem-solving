import sys
from collections import defaultdict

# N <= 50
N = int(sys.stdin.readline())
employees = list(map(int, sys.stdin.readline().split()))

tree = defaultdict(list)
for i in range(1, N):
    tree[employees[i]].append(i)
times = [0] * (N)


def dp(index):
    children = []
    for employee in tree[index]:
        dp(employee)
        children.append(times[employee])
    if not tree[index]:
        children.append(0)

    children.sort(reverse=True)

    needed_times = [children[i] + i + 1 for i in range(len(children))]
    times[index] = max(needed_times)


dp(0)
print(times[0] - 1)
