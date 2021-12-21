def solution(n, arr1, arr2):
    secret_map = [[0] * n for _ in range(n)]
    for i in range(n):
        # arr1_bits = ("0" * n + bin(arr1[i])[2:])[-n:]
        # arr2_bits = ("0" * n + bin(arr2[i])[2:])[-n:]
        arr1_bits = bin(arr1[i])[2:].rjust(n, "0")
        arr2_bits = bin(arr2[i])[2:].rjust(n, "0")

        for j in range(n):
            arr1_bit = int(arr1_bits[j])
            arr2_bit = int(arr2_bits[j])
            secret_map[i][j] = "#" if arr1_bit + arr2_bit > 0 else " "

    for i in range(n):
        secret_map[i] = "".join(secret_map[i])
    return secret_map
