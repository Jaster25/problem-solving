import sys

A, B, C = map(int, sys.stdin.readline().split())

# 1. 크기가 같지 않은 두 그룹 선택
# 2. 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y
# 3. X -> X+X, Y -> Y-X
# 4. 1~3 단계 반복하여 A==B==C가 되면 1 출력, 안되면 0 출력


def game(rock1, rock2):
    x = min(rock1, rock2)
    y = max(rock1, rock2)
    x2 = x + x
    y2 = y - x
    return x2, y2


is_same = False
is_visited = set()
while True:
    if A == B == C:
        is_same = True
        break

    if A != B:
        A, B = game(A, B)
    if B != C:
        B, C = game(B, C)
    if A != C:
        A, C = game(A, C)

    if (A, B, C) in is_visited:
        break
    is_visited.add((A, B, C))

if is_same:
    print(1)
else:
    print(0)
