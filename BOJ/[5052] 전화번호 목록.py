import sys


class Node:
    def __init__(self, number):
        self.number = number
        self.children = {}
        self.is_end = False


def insert_node(trie, numbers):
    node = trie
    for number in numbers:
        if number not in node.children:
            new_node = Node(number)
            node.children[number] = new_node
        node = node.children[number]
    # 목록에 있는 두 전화번호가 같은 경우는 없다.
    node.is_end = True


def is_consistent(node):
    if node.children and node.is_end:
        return False
    for child in node.children:
        if not is_consistent(node.children[child]):
            return False
    return True


t = int(sys.stdin.readline())
for _ in range(t):
    trie = Node(None)
    n = int(sys.stdin.readline())
    for _ in range(n):
        numbers = sys.stdin.readline().rstrip()
        insert_node(trie, numbers)

    if is_consistent(trie):
        print("YES")
    else:
        print("NO")
