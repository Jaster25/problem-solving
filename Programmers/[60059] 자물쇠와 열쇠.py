def rotate_matrix(m):
    # * rotate ->
    ml = len(m)
    rotated = [[0] * ml for _ in range(ml)]
    for i in range(ml):
        for j in range(ml):
            rotated[i][j] = m[ml - j - 1][i]
    return rotated


def add_matrix(lock, key, y, x):
    temp = list(map(lambda x: x[:], lock))
    for i in range(len(key)):
        for j in range(len(key)):
            temp[y + i][x + j] += key[i][j]
    return temp


def check_matrix(m, N):
    for i in range(N, 2*N):
        for j in range(N, 2*N):
            if m[i][j] != 1:
                return False
    return True


def solution(key, lock):
    N = len(lock)

    # * lock 확장 3N x 3N
    lock_extended = [[0] * 3 * N for _ in range(3*N)]
    for i in range(N, 2*N):
        for j in range(N, 2*N):
            lock_extended[i][j] = lock[i-N][j-N]

    # * key 회전시키고 이동하며 lock 홈에 다 넣어보기
    rotated_key = key
    for _ in range(4):
        for y in range(2*N):
            for x in range(2*N):
                # * N~2N 범위 다 1인지 확인
                if check_matrix(add_matrix(lock_extended, rotated_key, y, x), N):
                    return True
        rotated_key = rotate_matrix(rotated_key)

    return False


if __name__ == "__main__":
    key, lock = [[0, 0, 0], [1, 0, 0], [0, 1, 1]], [
        [1, 1, 1], [1, 1, 0], [1, 0, 1]]
    print(solution(key, lock))
