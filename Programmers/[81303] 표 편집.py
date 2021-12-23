# 5 ≤ n ≤ 1,000,000
# 0 ≤ k < n
# 1 ≤ cmd의 원소 개수 ≤ 200,000


def solution(n, k, cmd):
    linked_list = [Node(i) for i in range(n)]
    for i in range(n - 1):
        linked_list[i].down = linked_list[i + 1]
        linked_list[i + 1].up = linked_list[i]
    linked_list[n - 1].up = linked_list[n - 2]

    # cursor
    node = linked_list[k]

    stack = []
    for command in cmd:
        if command[0] == "U":
            index = int(command.split()[1])
            for _ in range(index):
                node = node.up
        elif command[0] == "D":
            index = int(command.split()[1])
            for _ in range(index):
                node = node.down
        elif command[0] == "C":
            stack.append(node)
            node.is_deleted = True
            if node.up is not None:
                node.up.down = node.down
            if node.down is not None:
                node.down.up = node.up

            if node.down is not None:
                node = node.down
            else:
                node = node.up
        elif command[0] == "Z":
            popped = stack.pop()
            popped.is_deleted = False
            if popped.up is not None:
                popped.up.down = popped
            if popped.down is not None:
                popped.down.up = popped

    answer = ""
    for i in range(n):
        if linked_list[i].is_deleted:
            answer += "X"
        else:
            answer += "O"
    return answer


class Node:
    def __init__(self, number):
        self.number = number
        self.down = None
        self.up = None
        self.is_deleted = False
