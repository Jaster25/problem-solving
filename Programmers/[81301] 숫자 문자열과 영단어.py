digitDict = {
    "zero": "0",
    "one": "1",
    "two": "2",
    "three": "3",
    "four": "4",
    "five": "5",
    "six": "6",
    "seven": "7",
    "eight": "8",
    "nine": "9",
}


def solution(s):
    answer = ""
    temp = []

    for char in s:
        temp.append(char)
        tempStr = "".join(temp)

        if tempStr.isdigit():
            answer += tempStr
            temp.clear()
        elif tempStr in digitDict:
            answer += digitDict[tempStr]
            temp.clear()
    return int(answer)
