import sys

N, K = map(int, sys.stdin.readline().split())
max_readable_count = 0

words = []
for _ in range(N):
    words.append(sys.stdin.readline().rstrip())

known_chars = [False] * 26
for char in ["a", "c", "t", "i", "n"]:
    known_chars[ord(char) - ord("a")] = True


def dfs(index, count):
    if count == K:
        readable_count = 0
        for word in words:
            for char in word:
                if not known_chars[ord(char) - ord("a")]:
                    break
            else:
                readable_count += 1
        global max_readable_count
        max_readable_count = max(readable_count, max_readable_count)
        return

    for i in range(index, 26):
        if not known_chars[i]:
            known_chars[i] = True
            dfs(i + 1, count + 1)
            known_chars[i] = False


if K < 5:  # 5: ["a", "n", "t", "i", "c"]
    print(0)
elif K == 26:
    print(N)
else:
    dfs(0, 5)
    print(max_readable_count)
