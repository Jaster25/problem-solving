def solution(n):
    answer = ""
    while n:
        n, remainer = divmod(n, 3)
        answer = "412"[remainer] + answer
        if remainer == 0:
            n -= 1
    return answer


if __name__ == "__main__":
    n = 14
    print(solution(n))
