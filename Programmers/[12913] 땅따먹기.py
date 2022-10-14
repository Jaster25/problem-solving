def solution(land):

    dp = [[0 for _ in range(4)] for _ in range(len(land))]
    for y in range(4):
        dp[0][y] = land[0][y]

    for y in range(1, len(land)):
        for x1 in range(4):
            candidates = []
            for x2 in range(4):
                if x1 == x2:
                    continue
                candidates.append(dp[y - 1][x2] + land[y][x1])
            dp[y][x1] = max(candidates)

    answer = max(dp[len(land) - 1])
    return answer
