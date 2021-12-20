from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        q1 = []
        q2 = []
        node = l1
        while node is not None:
            q1.append(node.val)
            node = node.next
        node = l2
        while node is not None:
            q2.append(node.val)
            node = node.next

        q1.reverse()
        q2.reverse()

        q1_list = int("".join(list(map(str, q1))))
        q2_list = int("".join(list(map(str, q2))))
        added = q1_list + q2_list
        reversed_added_str_list = list(str(added)[::-1])
        reversed_added_int_list = list(map(int, reversed_added_str_list))

        added_list_node = ListNode(val=reversed_added_int_list[0])
        node = added_list_node
        for a in reversed_added_int_list[1:]:
            newNode = ListNode(val=a)
            node.next = newNode
            node = newNode
        return added_list_node
