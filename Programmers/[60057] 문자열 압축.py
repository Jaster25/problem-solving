def solution(s):
    result = [len(s)]

    for i in range(1, len(s)//2 + 1):
        temp = ""
        cnt = 1
        sub_s = s[0:i]

        for j in range(i, len(s), i):
            if sub_s == s[j:j+i]:
                cnt += 1
            else:
                if cnt == 1:
                    temp += sub_s
                else:
                    temp += str(cnt) + sub_s
                sub_s = s[j:j+i]
                cnt = 1

        if cnt == 1:
            temp += sub_s
        else:
            temp += str(cnt) + sub_s
        result.append(len(temp))

    return min(result)
