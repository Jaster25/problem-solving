def solution(skill, skill_trees):
    answer = 0

    for st in skill_trees:
        idx = 0
        for i in range(len(st)):
            if st[i] in skill[idx+1:]:
                break
            elif st[i] == skill[idx]:
                idx += 1

            if i == len(st)-1 or idx == len(skill):
                answer += 1
                break

    return answer


"""
# for-else, pop(0)

skill = "CBD"
skill_trees = ["BACDE", "CBADF", "AECB", "BDA"]

print(solution(skill, skill_trees))
"""
