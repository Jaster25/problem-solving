from collections import defaultdict, deque


def is_connected(str1, str2):
    gap = 0
    for ch1, ch2 in zip(str1, str2):
        if ch1 != ch2:
            gap += 1
    return gap == 1


def solution(begin, target, words):
    is_visited = defaultdict(int)

    queue = deque([begin])
    is_visited[begin] = 1
    while queue:
        popped = queue.popleft()
        if popped == target:
            return is_visited[popped] - 1

        for word in words:
            if is_connected(popped, word):
                if is_visited[word] == 0:
                    queue.append(word)
                    is_visited[word] = is_visited[popped] + 1
    return 0
