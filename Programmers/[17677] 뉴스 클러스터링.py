def to_multiple_set(str):
    multiple_set = []
    for i in range(len(str) - 1):
        temp = str[i:i+2]
        if temp.isalpha():
            multiple_set.append(temp.upper())

    return multiple_set


def solution(str1, str2):
    set1, set2 = map(to_multiple_set, [str1, str2])

    intersect = set(set1) & set(set2)
    union = set(set1) | set(set2)

    cnt_intersect = sum(
        map(lambda x: min(set1.count(x), set2.count(x)), intersect))
    cnt_union = sum(
        map(lambda x: max(set1.count(x), set2.count(x)), union))

    if not cnt_intersect and not cnt_union:
        return 65536

    answer = int(cnt_intersect / cnt_union * 65536)
    return answer


if __name__ == "__main__":
    str1, str2 = "FRANCE", "french"
    # str1, str2 = "handshake", "shake hands"
    # str1, str2 = "aa1+aa2", "AAAA12"
    # str1, str2 = "E=M*C^2", "e=m*c^2"

    print(solution(str1, str2))
