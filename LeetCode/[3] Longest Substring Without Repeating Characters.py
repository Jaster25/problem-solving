from collections import deque


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        answer = 0
        ch_set = set()
        queue = deque()
        for ch in s:
            while ch in ch_set:
                ch_set.remove(queue.popleft())

            queue.append(ch)
            ch_set.add(ch)

            answer = max(len(ch_set), answer)
        return answer
