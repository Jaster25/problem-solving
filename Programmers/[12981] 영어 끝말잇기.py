def solution(n, words):
    answer = [1, 1]
    last_word = words[0]
    check = set([last_word])

    for word in words[1:]:
        # * update answer
        answer[0] += 1
        if answer[0] > n:
            answer[0] = 1
            answer[1] += 1

         # * check overlap
        if word in check:
            return answer
        check.add(word)

        # * check
        if last_word[-1] != word[0]:
            return answer

        # * update last_word
        last_word = word

    return [0, 0]


if __name__ == '__main__':
    n, words = 3, ["tank", "kick", "know", "wheel",
                   "land", "dream", "mother", "robot", "tank"]
    # n, words = 5, ["hello", "observe", "effect", "take", "either", "recognize", "encourage",
    #                "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"]
    # n, words = 2, ["hello", "one", "even", "never", "now", "world", "draw"]
    print(solution(n, words))
