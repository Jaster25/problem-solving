def getRank(sameNumberCount):
    if sameNumberCount >= 2:
        return 7 - sameNumberCount
    else:
        return 6


def solution(lottos, win_nums):
    winNumberSet = set(win_nums)
    lottoNumberSet = set(lottos)

    correctNumberCount = len(winNumberSet & lottoNumberSet)  # & == intersection()
    unrecognizableNumberCount = lottos.count(0)

    maxRank = getRank(correctNumberCount + unrecognizableNumberCount)
    minRank = getRank(correctNumberCount)
    return [maxRank, minRank]
