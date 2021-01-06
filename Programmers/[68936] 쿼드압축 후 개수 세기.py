import operator


def quard(arr):
    ar1, ar2, ar3, ar4 = [], [], [], []
    half = int(len(arr) / 2)

    for ar in arr[:half]:
        ar1.append(ar[:half])
    for ar in arr[half:]:
        ar2.append(ar[half:])
    for ar in arr[:half]:
        ar3.append(ar[half:])
    for ar in arr[half:]:
        ar4.append(ar[:half])

    return [ar1, ar2, ar3, ar4]


def solution(arr):
    if sum(list(map(sum, arr))) == len(arr)**2:
        return [0, 1]
    if sum(list(map(sum, arr))) == 0:
        return [1, 0]

    answer = [0, 0]
    for l in list(map(solution, quard(arr))):
        answer = list(map(operator.add, answer, l))
    return answer


if __name__ == '__main__':
    # arr = [[0, 0], [1, 1]]
    # arr = [[1, 1, 0, 0], [1, 0, 0, 0], [1, 0, 0, 1], [1, 1, 1, 1]]
    arr = [[1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 1, 1, 1, 1], [0, 1, 0, 0, 1, 1, 1, 1], [
        0, 0, 0, 0, 0, 0, 1, 1], [0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 1, 0, 0, 1], [0, 0, 0, 0, 1, 1, 1, 1]]
    print(solution(arr))
