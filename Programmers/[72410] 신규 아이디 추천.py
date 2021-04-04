def solution(new_id):
    # step1
    new_id = new_id.lower()

    # step2
    temp = ""
    for ch in new_id:
        if ch.isalnum() or ch in ["-", "_", "."]:
            temp += ch
    new_id = temp

    # step3
    while ".." in new_id:
        new_id = new_id.replace("..", ".")

    # step4
    if len(new_id) and new_id[0] == ".":
        new_id = new_id[1:]
    if len(new_id) and new_id[-1] == ".":
        new_id = new_id[:-1]

    # step5
    if not new_id:
        new_id = "a"

    # step6
    if len(new_id) >= 16:
        new_id = new_id[:15]
        if new_id[-1] == ".":
            new_id = new_id[:-1]

    # step7
    while len(new_id) < 3:
        new_id += new_id[-1]

    return new_id


if __name__ == "__main__":
    # new_id = "...!@BaT#*..y.abcdefghijklm"
    # new_id = "z-+.^."
    # new_id = "=.="
    new_id = "123_.def"
    print(solution(new_id))