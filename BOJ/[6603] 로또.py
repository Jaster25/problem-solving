from itertools import combinations

while True:
    testcase = input()
    if testcase == "0":
        break

    s = testcase.split()[1:]

    for case in combinations(s, 6):
        print(" ".join(case))
    print()
