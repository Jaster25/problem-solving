answer = 0


def dfs(numbers, target, current):
    if not numbers:
        if current == target:
            global answer
            answer += 1
        return
    number = numbers[0]
    dfs(numbers[1:], target, current + number)
    dfs(numbers[1:], target, current - number)


def solution(numbers, target):
    dfs(numbers, target, 0)
    return answer
