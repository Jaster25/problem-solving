parents = []


def makeParents(n):
    global parents
    parents = [i for i in range(n + 1)]


def findParent(number):
    parent = parents[number]
    if number != parent:
        parents[number] = findParent(parent)
    return parents[number]


def isSameParent(a, b):
    return findParent(a) == findParent(b)


def unionParent(a, b):
    aParent = findParent(a)
    bParent = findParent(b)
    if aParent < bParent:
        parents[bParent] = a
    else:
        parents[aParent] = b


def solution(n, costs):
    makeParents(n)

    costs.sort(key=lambda x: x[2])

    answer = 0
    for cost in costs:
        if not isSameParent(cost[0], cost[1]):
            unionParent(cost[0], cost[1])
            answer += cost[2]
    return answer
