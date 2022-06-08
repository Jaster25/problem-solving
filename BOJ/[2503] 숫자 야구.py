from itertools import permutations

N = int(input())
answer = list(permutations(["1", "2", "3", "4", "5", "6", "7", "8", "9"], 3))


def check_number(number, ask_number, strike_number, ball_number):
    strike_count = 0
    ball_count = 0
    str_ask_number = str(ask_number)

    for i in range(3):
        for j in range(3):
            if number[i] == str_ask_number[j]:  # 같은 숫자
                if i == j:  # 같은 위치: 스트라이크
                    strike_count += 1
                else:  # 다른 위치: 볼
                    ball_count += 1
    return strike_count == strike_number and ball_count == ball_number


for _ in range(N):
    # 질문 번호 / 스트라이크 개수 / 볼 개수
    ask_number, strike_number, ball_number = map(int, input().split())
    answer = list(filter(lambda number: check_number(number, ask_number, strike_number, ball_number), answer))

print(len(answer))
