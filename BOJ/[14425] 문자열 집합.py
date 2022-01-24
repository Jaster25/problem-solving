import sys


class Node:
    def __init__(self, data):
        self.data = data
        self.is_end = False
        self.children = {}


def insert_node(trie, word):
    node = trie
    for ch in word:
        if ch not in node.children:
            new_node = Node(ch)
            node.children[ch] = new_node
        node = node.children[ch]
    node.is_end = True


def is_included(trie, word):
    node = trie
    for ch in word:
        if ch not in node.children:
            return False
        node = node.children[ch]
    return node.is_end


N, M = map(int, sys.stdin.readline().split())
trie = Node(None)

for _ in range(N):
    word = sys.stdin.readline().rstrip()
    insert_node(trie, word)

count = 0
for _ in range(M):
    word = sys.stdin.readline().rstrip()
    if is_included(trie, word):
        count += 1
print(count)
