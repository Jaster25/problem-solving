import itertools
import math


def solution(nums):
    answer = 0
    temp = []
    list(map(lambda x: temp.append(sum(x)), itertools.combinations(nums, 3)))
    max_temp = max(temp)

    # * 에라토스테네스의 체
    visited = [False for _ in range(max_temp + 1)]
    prime = []
    for i in range(2, max_temp+1):
        if not visited[i]:
            prime.append(i)
            for j in range(max_temp):
                if i*j <= max_temp:
                    visited[i*j] = True
                else:
                    break

    for t in temp:
        if t in prime:
            answer += 1

    return answer


if __name__ == '__main__':
    nums = [1, 2, 7, 6, 4]
    print(solution(nums))
