# https://school.programmers.co.kr/learn/courses/30/lessons/12927#

import heapq


# 야근 피로도: 남은 작업량 제곱의 총합
def solution(n, works):
    pq = []
    for work in works:
        heapq.heappush(pq, -work)

    for _ in range(n):
        popped = -heapq.heappop(pq)

        if popped == 0:
            break

        heapq.heappush(pq, - (popped - 1))

    return get_stress_index(pq)


def get_stress_index(works):
    return sum(work ** 2 for work in works)