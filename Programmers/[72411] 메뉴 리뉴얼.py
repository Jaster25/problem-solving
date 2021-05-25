from itertools import combinations
from collections import Counter


def solution(orders, course):
    answer = []
    for n in course:
        table = []
        for menu in orders:
            for case in combinations(menu, n):
                table.append("".join(sorted(case)))

        table_cnt = Counter(table).most_common()

        for menu_list, cnt in table_cnt:
            if cnt > 1 and cnt == table_cnt[0][1]:
                answer.append(menu_list)

    return sorted(answer)


if __name__ == "__main__":
    # orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
    # course = [2, 3, 4]

    orders = ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"]
    course = [2, 3, 5]

    print(solution(orders, course))