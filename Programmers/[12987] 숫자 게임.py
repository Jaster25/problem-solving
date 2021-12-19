from collections import deque


def solution(A, B):
    answer = 0
    queueA = deque(sorted(A))
    queueB = deque(sorted(B))

    while queueB:
        if queueA[0] < queueB[0]:
            answer += 1
            queueA.popleft()
        queueB.popleft()
    return answer
