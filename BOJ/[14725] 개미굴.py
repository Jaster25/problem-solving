import sys


class Node:
    def __init__(self, data, depth):
        self.data = data
        self.children = {}
        self.depth = depth
        self.is_end = False


def insert_node(trie, words):
    node = trie
    for depth, word in enumerate(words):
        if word not in node.children:
            new_node = Node(word, depth + 1)
            node.children[word] = new_node
        node = node.children[word]
    node.is_end = True


def print_node(node):
    if node.depth != 0:
        print("--" * (node.depth - 1) + node.data)

    for key in sorted(node.children.keys()):
        print_node(node.children[key])


N = int(sys.stdin.readline())

trie = Node(None, 0)
for _ in range(N):
    info = list(sys.stdin.readline().split())
    insert_node(trie, info[1:])

print_node(trie)
