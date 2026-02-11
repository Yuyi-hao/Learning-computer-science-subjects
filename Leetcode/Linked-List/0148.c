// 148. Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *merge(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode *temp = dummy;
    while(list1 && list2){
        if(list1->val < list2->val){
            temp->next = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1){
        temp->next = list1;
    }
    if(list2){
        temp->next = list2;
    }
    struct ListNode *head = dummy->next;
    free(dummy);
    return head;
}

struct ListNode* sortList(struct ListNode* head) {
    if(!head || !(head->next)) return head;
    struct ListNode *slow = head, *fast = head->next->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *second = slow->next;
    slow->next = NULL;
    struct ListNode *first = sortList(head);
    second = sortList(second);
    struct ListNode *sorted_list = merge(first, second);
    return sorted_list;
}

// iterative code NOT MINE

// struct ListNode* sortList(struct ListNode* head){
//   /* Grab sublists of size 1, then 2, then 4, etc, until fully merged */
//   for (int steps = 1;; steps *= 2) {
//     /* Keep track of how much is left to process on this pass of the list */
//     struct ListNode* remaining = head;

//     /*
//     Record the progress of the current pass into a single semi sorted list by updating the next pointer
//     of the previous node (or the head on the first loop)
//     */
//     struct ListNode** next_ptr = &head;

//     int num_loops = 0;
//     for (; remaining; ++num_loops) {
//       /* Split 2 sublists of steps length from the front */
//       struct ListNode* sublists[2];
//       struct ListNode* sublists_tail[2] = {NULL, NULL};
//       for (int i = 0; i < 2; ++i) {
//         sublists[i] = remaining;
//         for (int j = 0; remaining && j < steps; ++j) {
//           sublists_tail[i] = remaining;
//           remaining = remaining->next;
//         }
//         /* Ensure the subslist (if one was made) is terminated */
//         if (sublists_tail[i]) {
//           sublists_tail[i]->next = NULL;
//         }
//       }

//       /* We have two sublists of (upto) length step that are sorted, merge them onto the end into a single list of (upto) step * 2 */
//       while (sublists[0] && sublists[1]) {
//         if (sublists[0]->val <= sublists[1]->val) {
//           *next_ptr = sublists[0];
//           next_ptr = &sublists[0]->next;
//           sublists[0] = sublists[0]->next;
//         } else {
//           *next_ptr = sublists[1];
//           next_ptr = &sublists[1]->next;
//           sublists[1] = sublists[1]->next;
//         }
//       }   

//       /* One list has been finished, attach what ever is left of the other to the end */
//       if (sublists[0]) {
//         *next_ptr = sublists[0];
//         next_ptr = &sublists_tail[0]->next;
//       } else {
//         *next_ptr = sublists[1];
//         next_ptr = &sublists_tail[1]->next;
//       }
//     }

//     /* If the entire list was fully processed in a single loop, it means we've completely sorted the list and are done */
//     if (1 >= num_loops) {
//       return head;
//     }
//   }
// }