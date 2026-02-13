# Linked List
This document summarizes all linked list topics, patterns, and LeetCode problems solved so far.

### Basic Traversal
- Iterative traversal
- Counting nodes
- Finding tail
- Printing list
- Safe NULL handling

```c
int getSize(struct ListNode *head) {
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}
```

### Dummy Node
Used to simplify:
- Head modification
- Insert at beginning
- Remove head cases
- Merge lists
```c
struct ListNode *dummy = (struct Node *)malloc(sizeof(struct Node));
dummy->next = head;

# free node
head = dummy->next;
free(dummy);
return head;
```

## Patterns

### Two Pointer (Fast & Slow)
- Cycle detection
- Finding middle
- Splitting list
- Removing nth from end

> If fast pointer assigned to third node in starting it can cancel out the case of even and odd nodes.
#### Problem Solve
- Linked List Cycle
- Linked List Cycle II
- Middle of Linked List
- Remove Nth Node From End

```c
struct ListNode *slow = head;
struct ListNode *fast = head;

while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```

### Reverse Pattern
- Reverse Linked List
- Reverse Linked List II
- Reverse Nodes in K Group
- Palindrome Linked List
```c
struct ListNode *prev = NULL;
struct ListNode *curr = head;

while (curr) {
    struct ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
return prev;
```