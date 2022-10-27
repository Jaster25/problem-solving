from collections import deque


def solution(queue1, queue2):
    sum_1 = sum(queue1)
    sum_2 = sum(queue2)
    deque1 = deque(queue1)
    deque2 = deque(queue2)

    for count in range(0, len(queue1) * 4):
        if sum_1 == sum_2:
            return count
        elif sum_1 < sum_2:
            number = deque2.popleft()
            deque1.append(number)
            sum_1 += number
            sum_2 -= number
        else:
            number = deque1.popleft()
            deque2.append(number)
            sum_1 -= number
            sum_2 += number
    return -1
