# 430. Flatten a Multilevel Doubly Linked List

"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

def solve(ll):
    if not ll:
        return None
    curr = ll
    while curr.next or curr.child:
        if curr.next:
            next_list = curr.next
        else:
            next_list = None
        if(curr.child):
            tail = solve(curr.child)
            curr.next = curr.child
            curr.child.prev = curr
            tail.next = next_list
            if next_list:
                next_list.prev = tail
            curr.child = None
        if next_list:
            curr = next_list
    return curr

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        solve(head)
        return head
        