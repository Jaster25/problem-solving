from itertools import combinations


def solution(relation):
    candidate_keys = []
    items_cnt = len(relation[0])
    items = [i for i in range(items_cnt)]

    for i in range(1, items_cnt+1):
        keys_list = list(combinations(items, i))
        for keys in keys_list:
            r = []
            for student in relation:
                s = []
                for key in keys:
                    s.append(student[key])
                if s not in r:
                    r.append(s)

            if len(r) == len(relation):
                for ck in candidate_keys:
                    if set(keys) | set(ck) == set(keys):
                        break
                else:
                    candidate_keys.append(keys)

    return len(candidate_keys)


if __name__ == "__main__":
    # relation = [["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], [
    #     "400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]

    relation = [['a', 'b', 'c'], ['1', 'b', 'c'],
                ['a', 'b', '4'], ['a', '5', 'c']]
    print(solution(relation))
