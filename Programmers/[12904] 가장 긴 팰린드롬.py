import sys

sys.setrecursionlimit(10 ** 6)


def check(sub_s):
    if len(sub_s) <= 1:
        return True

    if sub_s[0] != sub_s[-1]:
        return False
    return check(sub_s[1:-1])


def solution(s):
    for i in range(len(s), 0, -1):
        for start in range(len(s)):
            if len(s) < i + start:
                break

            if check(s[start : start + i]):
                return len(s[start : start + i])

    return 1


if __name__ == "__main__":
    # s = "abcdcba"
    # s = "abacde"
    s = "c"
    print(solution(s))
