import sys
import math

N = int(sys.stdin.readline())
applicants = map(int, sys.stdin.readline().split())
main, sub = map(int, sys.stdin.readline().split())

# 총감독관 수: N만큼

min_supervisor_count = N
for applicant in applicants:
    if applicant > main:
        applicant -= main
    else:
        applicant = 0
    min_supervisor_count += math.ceil(applicant / sub)

print(min_supervisor_count)
