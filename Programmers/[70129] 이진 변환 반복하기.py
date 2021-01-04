def solution(s):
    answer = [0, 0]
    while int(s) != 1:
        answer[0] += 1

        len_s = len(s)
        cnt_0 = s.count('0')
        s = bin(len_s-cnt_0)[2:]
        answer[1] += cnt_0

    return answer


# """
s = "110010101001"
print(solution(s))
# """
