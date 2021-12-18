def solution(n, times):
    left = 1
    answer = right = n * max(times)

    while left <= right:
        middle = (left + right) // 2

        count = 0
        for time in times:
            count += middle // time

        if count >= n:
            answer = middle
            right = middle - 1
        else:
            left = middle + 1
    return answer
