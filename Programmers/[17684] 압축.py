def solution(msg):
    answer = []
    DICT = {}

    num = 1
    for i in range(ord('A'), ord('Z')+1):
        DICT[chr(i)] = num
        num += 1

    idx = 0
    while idx < len(msg):
        c = 1
        while idx+c <= len(msg) and msg[idx:idx+c] in DICT:
            c += 1

        if msg[idx:idx+c] not in DICT:
            DICT[msg[idx:idx+c]] = num
            num += 1

        answer.append(DICT[msg[idx:idx+c-1]])
        idx += c-1
    return answer


if __name__ == "__main__":
    # msg = "KAKAO"
    # msg = "TOBEORNOTTOBEORTOBEORNOT"
    msg = "ABABABABABABABAB"
    print(solution(msg))
