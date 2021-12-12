def solution(numbers):
    sumSet = set()
    numbersLen = len(numbers)
    for i in range(numbersLen):
        for j in range(numbersLen):
            if i == j:
                continue
            sumSet.add(numbers[i] + numbers[j])

    # sorted()가 반환을 리스트로 알아서 해줌
    # sorted(list(sumSet)) -> sorted(sumSet)
    orderedSumSet = sorted(sumSet)

    return orderedSumSet
