def solution(cards1, cards2, goal):
    index1 = 0
    index2 = 0
    for word in goal:
        if (index1 < len(cards1) and word == cards1[index1]):
            index1 += 1
        elif (index2 < len(cards2) and word == cards2[index2]):
            index2 += 1
        else:
            return "No"
    
    return "Yes"