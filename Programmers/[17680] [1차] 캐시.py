from collections import deque


def solution(cacheSize, cities):
    if not int(cacheSize):
        return 5 * len(cities)

    answer = 0
    cache = deque()
    for city_ in cities:
        city = city_.upper()

        if city in cache:
            answer += 1
            cache.remove(city)
            cache.append(city)
        else:
            answer += 5
            if len(cache) == int(cacheSize):
                cache.popleft()
            cache.append(city)

    return answer


if __name__ == "__main__":
    # cacheSize = 3
    # cities = ["Jeju", "Pangyo", "Seoul", "NewYork",
    #           "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]

    cacheSize = 2
    cities = ["Jeju", "Pangyo", "NewYork", "newyork"]

    print(solution(cacheSize, cities))
