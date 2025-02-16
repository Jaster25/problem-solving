from collections import deque


def solution(s):
    
    queue = deque()

    for bracket in s:
        if bracket == '(':
            queue.append(bracket)
        else:
            if len(queue) == 0:
                return False
            
            popped = queue.pop()
            if popped != '(':
                return False

    return len(queue) == 0