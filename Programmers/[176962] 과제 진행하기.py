from collections import deque


def solution(plans):
    answer = []

    for plan in plans:
        plan[1] = convert_to_minutes(plan[1])
    plans.sort(key = lambda x: x[1])

    queue = deque()
    current_min = 0
    
    for assignment, start_min, playtime in plans:
        # dif_min: 다음 과제까지 활용 가능한 시간(다음 과제 시작 시간 - 최근 과제 시작 시간)
        dif_min = start_min - current_min
        current_min = start_min
        
        if len(queue) != 0:
            while queue:
                popped = queue.pop()
                
                # 활용 가능한 시간 내에서 쌓인 과제 순서대로 진행
                if dif_min >= popped[2]:
                    dif_min -= popped[2]
                    answer.append(popped[0])
                else:
                    # 또 다시 멈춘 과제는 진행한 시간만큼 처리하고 다시 큐에 추가
                    popped[2] -= dif_min
                    queue.append(popped)
                    break

        # 활용 가능한 시간 사용 후 다음 과제 큐에 추가
        queue.append([assignment, start_min, int(playtime)])

    # 쌓인 과제 처리
    while queue:
        answer.append(queue.pop()[0])

    return answer


def convert_to_minutes(start_time):
    return 60 * int(start_time[:2]) + int(start_time[3:])