import heapq


def solution(scoville, K):
    heap = []
    for score in scoville:
        heapq.heappush(heap, score)

    count = 0
    while heap[0] < K:
        if len(heap) == 1:
            return -1

        count += 1
        score1 = heapq.heappop(heap)
        score2 = heapq.heappop(heap)
        mixed_score = score1 + score2 * 2
        heapq.heappush(heap, mixed_score)

    return count
