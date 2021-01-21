def solution(stones, k):
    left, right = 0, 200000000

    def check(mid):
        cnt = 0
        for s in stones:
            if s - mid <= 0:
                cnt += 1
                if cnt == k:
                    return False
            else:
                cnt = 0
        return True

    while left <= right:
        mid = (left + right) // 2
        if check(mid):
            left = mid + 1
        else:
            right = mid - 1

    return left


if __name__ == "__main__":
    stones, k = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1],	3
    print(solution(stones, k))
