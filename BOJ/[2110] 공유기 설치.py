import sys

# 집의 개수 N (2 ≤ N ≤ 200,000)
# 공유기의 개수 C (2 ≤ C ≤ N)
N, C = map(int, sys.stdin.readline().split())


# 집의 좌표 (0 ≤ xi ≤ 1,000,000,000)
house = []
for _ in range(N):
    x = int(sys.stdin.readline())
    house.append(x)
house.sort()


def is_possible(minimum):
    count = 1
    last_position = house[0]
    for position in house[1:]:
        if position - last_position >= minimum:
            last_position = position
            count += 1
    return count


left = 1
right = house[-1]
answer = right
while left <= right:
    mid = (left + right) // 2
    if is_possible(mid) >= C:
        answer = mid
        left = mid + 1
    else:
        right = mid - 1
print(answer)
