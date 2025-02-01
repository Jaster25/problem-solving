"""
첫 번째 풀이: 순열로 진행 -> 시간초과
두 번째 풀이: DFS
"""

from itertools import permutations


min_total_stress = float('inf')


def solution(picks, minerals):

    dfs(picks, minerals, 0, 0)
    
    return min_total_stress


def dfs(picks, minerals, mineral_idx, total_stress):
    if sum(picks) == 0 or mineral_idx == len(minerals):
        global min_total_stress
        min_total_stress = min(total_stress, min_total_stress)
        return
    
    for pick_idx in range(3):
        if picks[pick_idx] > 0:
            stress = 0
            max_mineral_idx = min(mineral_idx + 5, len(minerals))
            for i in range(mineral_idx, max_mineral_idx):
                stress += mine(minerals[i], pick_idx)
            
            picks[pick_idx] -= 1
            dfs(picks, minerals, max_mineral_idx, total_stress + stress)
            picks[pick_idx] += 1


def mine(mineral, pick_idx):
    hardness = {
        # 광물
        'diamond': 25,
        'iron': 5,
        'stone': 1,
        # 곡괭이
        0: 25,
        1: 5,
        2: 1
    }

    return max(hardness[mineral] // hardness[pick_idx], 1)




# 순열 -> 시간초과
from itertools import permutations

def solution(picks, minerals):
    elements = ['diamond'] * picks[0] \
                + ['iron'] * picks[1] \
                + ['stone'] * picks[2]

    min_total_stress = float('inf')
    for pick_list in set(permutations(elements)):
        total_stress = 0
        
        pick_idx = 0
        pick_cnt = 0
        for mineral in minerals:
            if total_stress > min_total_stress:
                break
            
            # 하나의 곡괭이로 캘 수 있는 광물은 최대 5개
            if pick_cnt == 5:
                pick_cnt = 0
                pick_idx += 1
            
            # 더 사용할 곡괭이가 없을 때까지
            if pick_idx >= len(pick_list):
                break
            
            total_stress += mine(mineral, pick_list[pick_idx])
            pick_cnt += 1    

        min_total_stress = min(min_total_stress, total_stress)
    
    return min_total_stress


def mine(mineral, pick):
    hardness = {
        'diamond': 25,
        'iron': 5,
        'stone': 1
    }
    
    stress = max(hardness[mineral] // hardness[pick], 1)
    
    return stress
