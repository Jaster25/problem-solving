def solution(targets):
    answer = 0
    
    # 그리디
    targets.sort(key = lambda x: x[1])
    
    point = 0 
    for s, e in targets:
        if s >= point:
            answer += 1
            point = e

    return answer