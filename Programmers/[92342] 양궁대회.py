max_gap = -float("inf")
max_target = []


def dfs(n, enemy_target, target, index, used_count):
    if index == -1:
        if used_count == n:
            # 점수 계산
            gap = 0
            for i in range(11):
                target_score = 10 - i
                if enemy_target[i] > target[i]:
                    gap -= target_score
                elif enemy_target[i] < target[i]:
                    gap += target_score
                else:
                    if target[i] > 0:
                        gap -= target_score

            global max_gap, max_target
            if gap > 0 and max_gap < gap:
                max_gap = gap
                max_target = target[:]
        return

    for i in range(n - used_count + 1, -1, -1):
        target[index] = i
        dfs(n, enemy_target, target, index - 1, used_count + i)
        target[index] = 0


def solution(n, info):
    dfs(n, info, [0] * 11, 10, 0)

    if max_gap != -float("inf"):
        return max_target
    else:
        return [-1]
