from sys import stdin

TC = int(input())
for _ in range(TC):
    N, M, W = map(int, stdin.readline().split())
    road = [[] for _ in range(N + 1)]
    d = [987654321 for _ in range(N + 1)]
    is_return = False

    for _ in range(M):
        S, E, T = map(int, stdin.readline().split())
        road[S].append([T, E])
        road[E].append([T, S])
    for _ in range(W):
        S, E, T = map(int, stdin.readline().split())
        road[S].append([-T, E])

    for i in range(1, N + 1):
        for j in range(1, N + 1):
            for t, e in road[j]:
                if d[e] > t + d[j]:
                    d[e] = t + d[j]
                    if i == N:
                        is_return = True

    print("YES" if is_return else "NO")
