from collections import deque


def count_difference(A, B):
    cnt = 0
    for a, b in zip(A, B):
        if a != b:
            cnt += 1

    return cnt


def solution(begin, target, words):
    if target not in words:
        return 0

    visited = [False for _ in range(len(words))]
    Q = deque()

    for index, word in enumerate(words):
        if count_difference(begin, word) == 1:
            Q.append([word, 1])
            visited[index] = True

    while Q:
        cur_word, cur_cnt = Q.popleft()
        if cur_word == target:
            return cur_cnt

        for index, word in enumerate(words):
            if count_difference(cur_word, word) == 1 and not visited[index]:
                Q.append([word, cur_cnt + 1])
                visited[index] = True

    return 0


if __name__ == "__main__":
    # begin, target, words = "hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]
    begin, target, words = "hit", "cog", ["hot", "dot", "dog", "lot", "log"]
    print(solution(begin, target, words))
