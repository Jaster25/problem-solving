def solution(dartResult: str):

    bonuses = ("S", "D", "T")
    options = ("*", "#")

    scores = []
    number = ""
    for index, ch in enumerate(dartResult):
        if ch.isdigit():
            number += ch

        elif ch in bonuses:
            number = int(number)
            if ch == "D":
                number = number ** 2
            elif ch == "T":
                number = number ** 3

        elif ch in options:
            if ch == "*":
                number *= 2
                if len(scores) > 0:
                    scores[-1] = scores[-1] * 2
            else:
                number *= -1

        if index == len(dartResult) - 1 or (not dartResult[index].isdigit() and dartResult[index + 1].isdigit()):
            scores.append(number)
            number = ""

    return sum(scores)
