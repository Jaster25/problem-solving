from collections import defaultdict, deque


def get_parking_min(enter_time, out_time):
    enter_hour, enter_min = map(int, enter_time.split(":"))
    out_hour, out_min = map(int, out_time.split(":"))
    return out_hour * 60 + out_min - (enter_hour * 60 + enter_min)


def solution(fees, records):
    answer = []
    parking_records = defaultdict(deque)

    # 1 <= records의 길이 <= 1,000
    for record in records:
        time, car_number, state = record.split()
        parking_records[car_number].append(time)

    accumulated_records = defaultdict(int)
    for car_number in parking_records.keys():
        while parking_records[car_number]:
            parking_min = 0
            # 출차 기록이 없는 경우
            if len(parking_records[car_number]) == 1:
                enter_time = parking_records[car_number].popleft()
                out_time = "23:59"
                parking_min = get_parking_min(enter_time, out_time)
            else:
                enter_time = parking_records[car_number].popleft()
                out_time = parking_records[car_number].popleft()
                parking_min = get_parking_min(enter_time, out_time)
            accumulated_records[car_number] += parking_min

    # 차량 번호가 작은 자동차 순으로
    car_numbers = sorted(accumulated_records.keys())
    for car_number in car_numbers:
        parking_min = accumulated_records[car_number]

        # fees: 기본 시간(분), 기본 요금(원), 단위 시간(분), 단위 요금(원)
        price = fees[1]
        if parking_min > fees[0]:
            price += fees[3] * ((parking_min - fees[0]) // fees[2])
            if (parking_min - fees[0]) % fees[2] != 0:
                price += fees[3]
        answer.append(price)
    return answer
