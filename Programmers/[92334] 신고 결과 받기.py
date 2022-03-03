from collections import defaultdict


def solution(id_list, report, k):
    answer = []
    users = defaultdict(set)
    reported_count = defaultdict(int)

    for content in report:
        user, reported_user = content.split()
        users[user].add(reported_user)

    for user in users.keys():
        for reported_user in users[user]:
            reported_count[reported_user] += 1

    for user_id in id_list:
        count = 0
        for reported_user in users[user_id]:
            if reported_count[reported_user] >= k:
                count += 1
        answer.append(count)
    return answer
