import re


def solution(new_id):
    # step1
    answer = new_id.lower()
    # step2
    answer = re.sub("[^a-zA-Z0-9\-\_\.]", "", answer)
    # step3
    answer = re.sub("\.\.+", ".", answer)
    # step4
    answer = re.sub("^\.|\.$", "", answer)
    # step5
    if answer == "":
        answer = "a"
    # step6
    answer = re.sub("\.$", "", answer[:15])
    # step7
    while len(answer) < 3:
        answer += answer[-1]

    return answer


if __name__ == "__main__":
    # new_id = "...!@BaT#*..y.abcdefghijklm"
    # new_id = "z-+.^."
    new_id = "=.="
    # new_id = "123_.def"
    print(solution(new_id))