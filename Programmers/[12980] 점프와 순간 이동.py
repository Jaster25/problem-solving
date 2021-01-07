def solution(n):
    answer = 0
    while n:
        while not n % 2:
            n //= 2
        n -= 1
        answer += 1

    return answer


if __name__ == '__main__':
    n = 5
    print(solution(n))
