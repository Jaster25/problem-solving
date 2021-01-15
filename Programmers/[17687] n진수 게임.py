def transfer(num, n):
    if not num:
        return "0"

    NUMBER = ['0', '1', '2', '3', '4', '5', '6', '7',
              '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
    s = ""
    while num:
        s = NUMBER[num % n] + s
        num //= n

    return s


def solution(n, t, m, p):
    s = ""
    num = 0
    while len(s) < t*m:
        s += transfer(num, n)
        num += 1

    return s[p-1::m][:t]


if __name__ == "__main__":
    # n, t, m, p = 2, 4, 2, 1
    # n, t, m, p = 16, 16, 2, 1
    n, t, m, p = 16, 16, 2, 2
    print(solution(n, t, m, p))
