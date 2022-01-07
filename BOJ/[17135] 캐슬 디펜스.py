import sys
from collections import deque
from itertools import combinations

# 3 ≤ N, M ≤ 15
# 1 ≤ D ≤ 10
# D: 궁수의 사거리
N, M, D = map(int, sys.stdin.readline().split())

MAP = []
enemy_list = []
for y in range(N):
    row = list(map(int, sys.stdin.readline().split()))
    for x in range(M):
        if row[x] == 1:
            enemy_list.append([y, x])


def get_distance(archer, enemy):
    return abs(archer[0] - enemy[0]) + abs(archer[1] - enemy[1])


def attack_enemy(attacked_set, current_enemy_list, archer):
    # possible[distance][enemy_y][enemy_x]
    possible = []
    for enemy in current_enemy_list:
        distance = get_distance(archer, enemy)
        if distance <= D:
            possible.append([distance, enemy[0], enemy[1]])

    # 정렬 기준: 1. 가장 가까운 거리, 2. 가장 왼쪽
    possible.sort(key=lambda x: (x[0], x[2]))

    if len(possible):
        attacked_set.add(str(possible[0][1]) + " " + str(possible[0][2]))


max_eliminated_count = 0

# 궁수 좌표 3개 조합
for archer_x_list in combinations([i for i in range(M)], 3):
    current_enemy_list = deque(enemy_list[:])
    current_attacked_count = 0

    while len(current_enemy_list) > 0:
        # 공격(중복 가능 -> set)
        attacked_set = set()
        for archer_x in archer_x_list:
            attack_enemy(attacked_set, current_enemy_list, [N, archer_x])

        # 공격당한 적 처리
        current_attacked_count += len(attacked_set)
        for enemy in attacked_set:
            y, x = map(int, enemy.split())
            current_enemy_list.remove([y, x])

        # 남아있는 적 처리
        # 최하단: 제외
        # 나머지: 한 칸씩 아래로 이동
        for _ in range(len(current_enemy_list)):
            y, x = current_enemy_list.popleft()
            if y != N - 1:
                current_enemy_list.append([y + 1, x])
    max_eliminated_count = max(current_attacked_count, max_eliminated_count)

print(max_eliminated_count)
