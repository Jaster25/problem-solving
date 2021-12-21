from collections import defaultdict

# 선수의 수는 1명 이상 100명 이하입니다.
# 경기 결과는 1개 이상 4,500개 이하입니다.


def solution(n, results):
    winner_set = defaultdict(set)  # i에게 이긴 사람들
    loser_set = defaultdict(set)  # i에게 진 사람들
    for winner, loser in results:
        winner_set[winner].add(loser)
        loser_set[loser].add(winner)

    for i in range(1, n + 1):
        for winner in winner_set[i]:
            loser_set[winner].update(loser_set[i])
        for loser in loser_set[i]:
            winner_set[loser].update(winner_set[i])

    answer = 0
    for i in range(1, n + 1):
        if len(winner_set[i]) + len(loser_set[i]) == n - 1:
            answer += 1

    return answer
