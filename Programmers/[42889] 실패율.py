from collections import Counter


def solution(N, stages):
    # stage_result = [0] * (N + 2)
    # for stage in stages:
    #     stage_result[stage] += 1
    stage_result = Counter(stages)

    failure_lates = []
    total = stage_result[N + 1]  # 다 깬 사람
    for stage in range(N, 0, -1):
        if stage_result[stage] == 0:
            failure_lates.append([stage, 0])
        else:
            failure_late = stage_result[stage] / (stage_result[stage] + total)
            failure_lates.append([stage, failure_late])
        total += stage_result[stage]

    failure_lates.sort(key=lambda x: (-x[1], x[0]))

    answer = list(map(lambda x: x[0], failure_lates))
    return answer
