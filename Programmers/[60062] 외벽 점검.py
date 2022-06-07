from itertools import permutations

# 순환 구조 풀이
# 1. 복사하여 연장
# 2. (index + 1) % n


def solution(n, weak, dist):
    min_friends_count = float("inf")
    weaks = weak + [w + n for w in weak]

    for i, start in enumerate(weak):
        for friends in permutations(dist):
            friends_count = 1
            position = start

            for friend in friends:
                position += friend

                if position < weaks[i + len(weak) - 1]:  # 끝인지 확인
                    friends_count += 1
                    # 바로 다음 취약 위치로 이동
                    position = [w for w in weaks[i + 1 : i + len(weak)] if w > position][0]
                else:
                    min_friends_count = min(friends_count, min_friends_count)
    return min_friends_count if min_friends_count != float("inf") else -1
