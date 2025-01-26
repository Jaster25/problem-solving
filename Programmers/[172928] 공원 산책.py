def solution(park, routes):
    y, x = find_start_position(park)
    
    directions = {
        "N": (-1, 0),
        "S": (1, 0),
        "W": (0, -1),
        "E": (0, 1),
    }
    
    for route in routes:
        move_dir, move_cnt_str = route.split(" ")
        move_cnt = int(move_cnt_str)
        
        if can_move(park, y, x, directions[move_dir], move_cnt):
            dy, dx = directions[move_dir]
            y += dy * move_cnt
            x += dx * move_cnt
        
    return y, x


def find_start_position(park):
    for i in range(0, len(park)):
        for l in range(0, len(park[i])):
            if park[i][l] == 'S':
                return i, l

            
def can_move(park, y, x, direction, move_cnt):
    dy, dx = direction
    
    for _ in range(move_cnt):
        y += dy
        x += dx
        
        # 공원을 벗어나는지 확인
        if y < 0 or len(park) <= y or x < 0 or len(park[0]) <= x:
            return False
        # 장애물을 만나는지 확인
        if  park[y][x] == "X":
            return False
        
    return True