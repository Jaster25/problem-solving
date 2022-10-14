def solution(cacheSize, cities):
    answer = 0

    cache = []
    for city in cities:
        city = city.lower()
        if city in cache:
            answer += 1
            cache.remove(city)
        else:
            answer += 5
            if 0 < len(cache) and len(cache) == cacheSize:
                cache = cache[1:]

        if len(cache) < cacheSize:
            cache.append(city)

    return answer
