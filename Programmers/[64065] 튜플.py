
def solution(s):
    answer = []
    nums_list = list(map(lambda x: x.split(','), s[2:-2].split('},{')))

    nums_list.sort(key=lambda x: len(x))
    for nums in nums_list:
        for num in nums:
            if int(num) not in answer:
                answer.append(int(num))

    return answer


"""
s = "{{1,2,3},{2,1},{1,2,4,3},{2}}"
print(solution(s))
"""
