keypad = {
    "1": (0, 0),
    "2": (0, 1),
    "3": (0, 2),
    "4": (1, 0),
    "5": (1, 1),
    "6": (1, 2),
    "7": (2, 0),
    "8": (2, 1),
    "9": (2, 2),
    "*": (3, 0),
    "0": (3, 1),
    "#": (3, 2),
}


def getDistance(thumb, number):
    thumbY, thumbX = keypad[thumb]
    numberY, numberX = keypad[number]
    return abs(thumbY - numberY) + abs(thumbX - numberX)


def solution(numbers, hand):
    answer = ""
    leftThumb = "*"
    rightThumb = "#"

    for number in numbers:
        numberStr = str(number)
        if numberStr in ["1", "4", "7", "*"]:
            leftThumb = numberStr
            answer += "L"
        elif numberStr in ["3", "6", "9", "#"]:
            rightThumb = numberStr
            answer += "R"
        else:
            leftDistance = getDistance(leftThumb, numberStr)
            rightDistance = getDistance(rightThumb, numberStr)
            if leftDistance < rightDistance:
                leftThumb = numberStr
                answer += "L"
            elif leftDistance > rightDistance:
                rightThumb = numberStr
                answer += "R"
            else:
                if hand == "left":
                    leftThumb = numberStr
                    answer += "L"
                else:
                    rightThumb = numberStr
                    answer += "R"
    return answer


if __name__ == "__main__":
    numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
    hand = "right"
    print(solution(numbers, hand))
