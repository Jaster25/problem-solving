def solution(players, m, k):
    answer = 0

    server_count = [0] * 48 # 1 <= k <= 24

    for hour in range(24):
        current_server_count = server_count[hour]
        need_server_count = players[hour] // m

        increased_server_count = current_server_count - need_server_count
        if increased_server_count < 0:            
            for i in range(k):
                server_count[hour + i] -= increased_server_count

            answer -= increased_server_count

    return answer