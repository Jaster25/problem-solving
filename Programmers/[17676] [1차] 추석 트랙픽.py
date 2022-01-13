def get_detail_time(log):
    date, time, process_time = log.split()

    date = int(date.split("-")[2]) * 24 * 60 * 60 * 1000
    hour, min, sec = time.split(":")
    hour = int(hour) * 60 * 60 * 1000
    min = int(min) * 60 * 1000
    sec = int(float(sec) * 1000)
    process_time = int(float(process_time[:-1]) * 1000)

    end_time = date + hour + min + sec
    start_time = end_time - process_time + 1
    return [start_time, end_time]


def count_overlapped_time(logs, time):
    count = 0
    for log in logs:
        if log[0] < time + 1000 and log[1] >= time:
            count += 1
    return count


def solution(lines):
    max_throughput_per_sec = 0
    logs = []

    for log in lines:
        start_time, end_time = get_detail_time(log)
        logs.append([start_time, end_time])

    for i in range(len(lines)):
        based_on_start_time = count_overlapped_time(logs, logs[i][0])
        based_on_end_time = count_overlapped_time(logs, logs[i][1])
        max_throughput_per_sec = max(based_on_start_time, based_on_end_time, max_throughput_per_sec)
    return max_throughput_per_sec
