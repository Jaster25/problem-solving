max_gap = 0
max_gap_list = [-1]


def check_gap(info: list, targets: list):
    gap = 0
    for i in range(11):
        if info[i] < targets[i]:
            gap += 10 - i
        elif info[i] > 0:
            gap -= 10 - i
    return gap


def dfs(info: list, targets: list, index, remaining_count):
    if index == -1:
        if remaining_count == 0:
            gap = check_gap(info, targets)
            global max_gap, max_gap_list
            if gap > 0 and gap > max_gap:
                max_gap = gap
                max_gap_list = targets[:]
        return

    for count in range(remaining_count, -1, -1):
        targets[index] = count
        dfs(info, targets, index - 1, remaining_count - count)
        targets[index] = 0


def solution(n, info):

    dfs(info, [0 for _ in range(11)], 10, n)

    return max_gap_list
