paper_count = int(input())
matrix = [[0] * 100 for _ in range(100)]

# start_y, start_x, end_y, end_x
def is_possible(y1, x1, y2, x2):
    for y in range(y1, y2 + 1):
        for x in range(x1, x2 + 1):
            if matrix[y][x] == 0:
                return False
    return True


for _ in range(paper_count):
    x, y = map(int, input().split())
    for i in range(10):
        for j in range(10):
            matrix[y + i][x + j] = 1

max_area = 0
for start_y in range(100):
    for start_x in range(100):
        if matrix[start_y][start_x] == 0:
            continue

        for end_y in range(start_y, 100):
            if matrix[end_y][start_x] == 0:
                break
            for end_x in range(start_x, 100):
                if matrix[end_y][end_x] == 0:
                    break

                if is_possible(start_y, start_x, end_y, end_x):
                    area = (end_y - start_y + 1) * (end_x - start_x + 1)
                    max_area = max(area, max_area)
print(max_area)
