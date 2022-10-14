import math


def convert_to_kth(n, k):
    string = ""
    while n >= k:
        string += str(n % k)
        n = n // k
    string += str(n)
    string = string[::-1]
    return string


def is_prime(number):
    if number == 1:
        return False

    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True


def solution(n, k):

    converted_n = convert_to_kth(n, k)

    answer = 0
    for sub_string in converted_n.split("0"):
        if sub_string == "":
            continue

        number = int(sub_string)
        if is_prime(number):
            answer += 1
    return answer
