def solution(storey):
    answer = 0

    while storey > 0:
        last_number = storey % 10

        if last_number > 5:
            answer += 10 - last_number
            storey += 10

        elif last_number < 5:
            answer += last_number

        else: # last_number == 5
            before_last_number = storey // 10 % 10

            if before_last_number >= 5:
                answer += 10 - last_number
                storey += 10
            else:
                answer += last_number

        storey //= 10

    return answer