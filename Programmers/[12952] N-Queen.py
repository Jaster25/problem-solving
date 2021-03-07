def solution(N):
    global answer
    answer = 0
    line = [0] * N

    def check(i):
        for j in range(i):
            if line[i] == line[j] or abs(line[i] - line[j]) == (i - j):
                return False
        return True

    def place_queen(index):
        if index == N:
            global answer
            answer += 1
        else:
            for i in range(N):
                line[index] = i
                if check(index):
                    place_queen(index + 1)

    place_queen(0)
    return answer


if __name__ == "__main__":
    N = 12
    print(solution(N))