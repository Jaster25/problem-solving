from collections import deque
import sys
sys.setrecursionlimit(10**6)


class Node:
    list_preorder = deque()
    list_postorder = deque()

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert_node(self, data):
        if self.data[0] < data[0]:
            if self.right:
                self.right.insert_node(data)
            else:
                self.right = Node(data)
        else:
            if self.left:
                self.left.insert_node(data)
            else:
                self.left = Node(data)

    def preorder(self):
        self.list_preorder.append(self.data)
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()

    def postorder(self):
        if self.left:
            self.left.postorder()
        if self.right:
            self.right.postorder()
        self.list_postorder.append(self.data)


def solution(nodeinfo):
    answer = [[], []]

    Q = deque(sorted(nodeinfo, key=lambda x: x[1], reverse=True))
    tree = Node(Q.popleft())
    while Q:
        tree.insert_node(Q.popleft())

    tree.preorder()
    tree.postorder()

    while tree.list_preorder:
        answer[0].append(nodeinfo.index(tree.list_preorder.popleft()) + 1)
    while tree.list_postorder:
        answer[1].append(nodeinfo.index(tree.list_postorder.popleft()) + 1)

    return answer


if __name__ == "__main__":
    nodeinfo = [[5, 3], [11, 5], [13, 3], [3, 5],
                [6, 1], [1, 3], [8, 6], [7, 2], [2, 2]]
    print(solution(nodeinfo))
