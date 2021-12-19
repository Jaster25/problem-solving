from itertools import permutations


def is_banned(banned_id, user_id):
    if len(banned_id) != len(user_id):
        return False
    for c1, c2 in zip(banned_id, user_id):
        if c1 == "*":
            continue
        if c1 != c2:
            return False
    return True


def solution(user_id, banned_id):
    banned_users = set()
    for case in permutations(user_id, len(banned_id)):
        for i in range(len(banned_id)):
            if not is_banned(banned_id[i], case[i]):
                break
        else:
            banned_users.add("".join(sorted(case)))
    return len(banned_users)
