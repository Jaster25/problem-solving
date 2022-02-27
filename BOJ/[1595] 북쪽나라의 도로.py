import sys
from collections import defaultdict, deque

# 도시 개수 <= 10,000
graph = defaultdict(list)
city_set = set()

while True:
    try:
        city1, city2, distance = map(int, sys.stdin.readline().split())
        city_set.add(city1)
        city_set.add(city2)
        graph[city1].append([city2, distance])
        graph[city2].append([city1, distance])
    except:
        break

# 거리가 가장 먼 두 도시 사이의 거리를 출력
max_distance = 0
for start_city in city_set:
    distances = [float("inf")] * (max(city_set) + 1)
    queue = deque()

    distances[start_city] = 0
    queue.append(start_city)
    while queue:
        city = queue.popleft()
        for connected_city, distance in graph[city]:
            if distances[connected_city] > distances[city] + distance:
                distances[connected_city] = distances[city] + distance
                queue.append(connected_city)

    for city in city_set:
        max_distance = max(max_distance, distances[city])

print(max_distance)
