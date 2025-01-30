def solution(name, yearning, photos):
    yearning_map = {name[i]: yearning[i] for i in range(len(name))}
    
    result = []
    for photo in photos:
        total_yearning = 0
        for p in photo:
            total_yearning += yearning_map.get(p, 0)
        result.append(total_yearning)

    return result