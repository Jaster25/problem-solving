def solution(n, times):
    left = 1
    right = n * max(times)

    while left < right:
        mid = (left + right) // 2
        cnt = 0

        for time in times:
            cnt += mid // time

        if cnt >= n:
            right = mid
        else:
            left = mid + 1

    return left


if __name__ == "__main__":
    n, times = 6, [7, 10]
    print(solution(n, times))
