from collections import deque


def solution(numbers, target):
    answer = 0

    Q = deque()
    Q.append([+numbers[0], 0])
    Q.append([-numbers[0], 0])

    while Q:
        current, idx = Q.popleft()

        if idx == len(numbers) - 1:
            if current == target:
                answer += 1
        else:
            Q.append([current + numbers[idx + 1], idx + 1])
            Q.append([current - numbers[idx + 1], idx + 1])

    return answer


if __name__ == "__main__":
    numbers = [1, 1, 1, 1, 1]
    target = 3
    print(solution(numbers, target))
