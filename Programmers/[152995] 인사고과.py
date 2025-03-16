# https://school.programmers.co.kr/learn/courses/30/lessons/152995


def solution(scores):
    answer = 1
    
    target_score = scores[0]
    scores.sort(key = lambda x: (-x[0], x[1]))

    max_score_b = -1
    for score_a, score_b in scores:
        if score_b >= max_score_b:
            max_score_b = score_b
            # 완호보다 석차가 좋은 경우
            if score_a + score_b > sum(target_score):
                answer += 1
        # 완호가 인센티브를 받지 못하는 경우 -1을 return 
        elif score_a == target_score[0] and score_b == target_score[1]:
                return -1

    return answer