n = int(input())
a = list(map(int, input().split(" ")))
add_count, sub_count, mul_count, div_count = map(int, input().split(" "))

# 출력: 최댓값, 최솟값
max_result = float("-inf")
min_result = float("inf")


def divide_negative_number(number, divide_number):
    if number < 0:
        return -1 * (-number // divide_number)
    else:
        return number // divide_number


# 백트래킹
def dfs(result, index, used_add_count, used_sub_count, used_mul_count, used_div_count):
    if index == n:
        global max_result, min_result
        max_result = max(result, max_result)
        min_result = min(result, min_result)
        return

    if add_count >= used_add_count + 1:
        dfs(result + a[index], index + 1, used_add_count + 1, used_sub_count, used_mul_count, used_div_count)
    if sub_count >= used_sub_count + 1:
        dfs(result - a[index], index + 1, used_add_count, used_sub_count + 1, used_mul_count, used_div_count)
    if mul_count >= used_mul_count + 1:
        dfs(result * a[index], index + 1, used_add_count, used_sub_count, used_mul_count + 1, used_div_count)
    if div_count >= used_div_count + 1:
        div_result = divide_negative_number(result, a[index])
        dfs(div_result, index + 1, used_add_count, used_sub_count, used_mul_count, used_div_count + 1)


dfs(a[0], 1, 0, 0, 0, 0)

print(max_result)
print(min_result)
