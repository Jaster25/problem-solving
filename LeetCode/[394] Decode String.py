from collections import deque


class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for ch in list(s):
            if ch == "]":
                string = deque()
                while stack[-1] != "[":
                    string.appendleft(stack.pop())
                # pop '['
                stack.pop()

                number = deque()
                while len(stack) > 0 and stack[-1].isdigit():
                    number.appendleft(stack.pop())

                stack.extend(int("".join(number)) * "".join(string))
            else:
                stack.append(ch)
        return "".join(stack)
