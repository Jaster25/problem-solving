from collections import deque


def solution(record):
    answer, room = [], {}
    Q = deque()

    for S in record:
        s = S.split()
        if s[0] != "Change":
            Q.append(s[1]), Q.append(s[0])
        if len(s) == 3:
            room[s[1]] = s[2]

    while Q:
        id, action = Q.popleft(), Q.popleft()
        s = room[id] + "님이 "
        if action == "Enter":
            s += "들어왔습니다."
        else:
            s += "나갔습니다."
        answer.append((s))

    return answer


if __name__ == "__main__":
    record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo",
              "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]
    print(solution(record))
