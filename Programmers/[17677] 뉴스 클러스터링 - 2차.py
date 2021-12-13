def jaccard(set1, set2):
    set1Length = len(set1)
    set2Length = len(set2)

    intersectionCount = 0
    for s in set1:
        if s in set2:
            intersectionCount += 1
            set2.remove(s)
            continue

    unionCount = set1Length + set2Length - intersectionCount

    if intersectionCount == 0 and unionCount == 0:
        return 65536
    return int((intersectionCount / unionCount) * 65536)


def getMultipleSet(str):
    multipleSet = []
    for i in range(len(str) - 1):
        extractedStr = str[i : i + 2]
        if extractedStr.isalpha():
            multipleSet.append(extractedStr.lower())
    return multipleSet


def solution(str1, str2):
    multipleSet1 = getMultipleSet(str1)
    multipleSet2 = getMultipleSet(str2)
    return jaccard(multipleSet1, multipleSet2)


if __name__ == "__main__":
    print(solution("FRANCE", "french"))
    print(solution("aa1+aa2", "AAAA12"))
    print(solution("E=M*C^2", "e=m*c^2"))
