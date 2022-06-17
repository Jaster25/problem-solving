from collections import deque

n, s = map(int, input().split(" "))
list = list(map(int, input().split(" ")))

min_length = float("inf")

queue = deque()
front_index = 0
back_index = 0
sum = 0

while front_index < n:
    if sum < s:
        if back_index >= n:
            break

        queue.append(list[back_index])
        sum += list[back_index]
        back_index += 1
    else:
        current_length = back_index - front_index
        min_length = min(current_length, min_length)

        popped_number = queue.popleft()
        sum -= popped_number
        front_index += 1

print(min_length if min_length != float("inf") else 0)
