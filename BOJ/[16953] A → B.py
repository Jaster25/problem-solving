from collections import deque

A, B = map(int, input().split())

min_count = -1
is_visited = set()
queue = deque()

is_visited.add(A)
queue.append([A, 0])
while queue:
    number, count = queue.popleft()
    if number == B:
        min_count = count + 1
        break

    for new_number in [number * 2, number * 10 + 1]:
        if new_number <= B:
            if new_number not in is_visited:
                is_visited.add(new_number)
                queue.append([new_number, count + 1])

print(min_count)
