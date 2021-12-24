import sys

N, M = map(int, sys.stdin.readline().split())

known = list(map(int, sys.stdin.readline().split()))
known_set = set(known[1:])

parties = []
for _ in range(M):
    party = list(map(int, sys.stdin.readline().split()))
    party_set = set(party[1:])
    parties.append(party_set)

for _ in range(M):
    for party_set in parties:
        if known_set & party_set:
            known_set.update(party_set)

answer = 0
for party_set in parties:
    if not known_set & party_set:
        answer += 1
print(answer)
