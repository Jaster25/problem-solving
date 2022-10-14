from collections import deque


def solution(begin, target, words):
    queue = deque()
    visited = set()
    queue.append([begin, 0])
    visited.add(begin)
    while queue:
        popped_word, popped_count = queue.popleft()
        if popped_word == target:
            return popped_count

        for word in words:
            if word in visited:
                continue

            different_count = 0
            for ch1, ch2 in zip(word, popped_word):
                if ch1 != ch2:
                    different_count += 1

            if different_count == 1:
                visited.add(word)
                queue.append([word, popped_count + 1])
    return 0
