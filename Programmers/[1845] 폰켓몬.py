def solution(s):
    pokemon = list(map(int, str(s)[1:-1].split(',')))
    kind = set(pokemon)

    return min(len(kind), len(pokemon)//2)
