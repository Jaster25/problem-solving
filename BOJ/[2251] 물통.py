from collections import deque


def solution():
    answer = []
    A, B, C = map(int, input().split())
    visited = [[False] * 201 for _ in range(201)]

    Q = deque([[0, 0, C]])
    while Q:
        a, b, c = Q.popleft()
        if visited[a][b]:
            continue
        visited[a][b] = True
        if a == 0 and c not in answer:
            answer.append(c)

        # * A->B
        if a+b <= B:
            Q.append([0, a+b, c])
        else:
            Q.append([a+b-B, B, c])
        # ! A->C
        Q.append([0, b, a+c])
        # * B->A
        if a+b <= A:
            Q.append([a+b, 0, c])
        else:
            Q.append([A, a+b-A, c])
        # ! B->C
        Q.append([a, 0, b+c])
        # * C->A
        if a+c <= A:
            Q.append([a+c, b, 0])
        else:
            Q.append([A, b, a+c-A])
        # * C->B
        if b+c <= B:
            Q.append([a, b+c, 0])
        else:
            Q.append([a, B, b+c-B])

    for v in sorted(answer):
        print(v, end=' ')


solution()
