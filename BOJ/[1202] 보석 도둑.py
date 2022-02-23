import sys
import heapq

# (1 <= N, K <= 300,000)
N, K = map(int, sys.stdin.readline().split())

# (0 <= Mi, Vi <= 1,000,000)
# 보석은 무게 Mi와 가격 Vi를 가지고 있다.
jewels = []
for _ in range(N):
    m, v = map(int, sys.stdin.readline().split())
    heapq.heappush(jewels, [m, v])

# (1 <= Ci <= 100,000,000)
# 각 가방에 담을 수 있는 최대 무게는 Ci이다.
# 가방에는 최대 한 개의 보석만 넣을 수 있다.
bags = []
for _ in range(K):
    c = int(sys.stdin.readline())
    bags.append(c)

bags.sort()


answer = 0
possible_jewels = []
for bag in bags:
    while jewels and bag >= jewels[0][0]:
        # heapq는 최소힙이 디폴트
        heapq.heappush(possible_jewels, -heapq.heappop(jewels)[1])

    if possible_jewels:
        answer -= heapq.heappop(possible_jewels)
    elif not jewels:
        break

print(answer)
