N = input()
M = int(input())

btn = {str(i) for i in range(10)}
if M:
    btn -= set(list(input().split()))

cnt_justmove = abs(int(N)-100)

cnt = float('inf')
for channel in range(1000001):
    for num in str(channel):
        if num not in btn:
            break
    else:
        cnt = min(abs(int(N)-channel) + len(str(channel)), cnt)

print(min(cnt, cnt_justmove))
