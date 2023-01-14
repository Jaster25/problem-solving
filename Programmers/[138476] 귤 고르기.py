from collections import Counter


def solution(k, tangerine):
    sorted_tangerine = sorted(Counter(tangerine).items(), reverse=True, key=lambda x: x[1])

    sort_count = 0
    pick_count = 0
    for size, number in sorted_tangerine:
        sort_count += 1
        pick_count += number

        if pick_count >= k:
            break

    return sort_count
