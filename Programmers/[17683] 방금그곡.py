def transfer_sharp(s):
    return "".join(list(map(lambda x: x[:-1] + chr(ord(x[-1])+10), s.split('#')[:-1]))) + s.split('#')[-1]


def solution(m, musicinfos):
    answer = []
    m_ = transfer_sharp(m)

    for music in musicinfos:
        info = music.split(',')
        music_ = transfer_sharp(info[3])

        t1 = 60 * int(info[0][:2]) + int(info[0][3:5])
        t2 = 60 * int(info[1][:2]) + int(info[1][3:5])
        music_time = t2 - t1

        if len(music_) >= music_time:
            melody = music_[:music_time]
        else:
            melody = music_ * (music_time // len(music_)) + \
                music_[:music_time % len(music_)]

        if m_ in melody:
            answer.append([music_time, len(answer), info[2]])

    if answer:
        answer.sort(key=lambda x: (-x[0], x[1]))
        return answer[0][2]

    return "(None)"


if __name__ == "__main__":
    # m = "ABCDEFG"
    # musicinfos = ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]
    m = "CC#BCC#BCC#BCC#B"
    musicinfos = ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]
    # m = "ABC"
    # musicinfos = ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]
    print(solution(m, musicinfos))
