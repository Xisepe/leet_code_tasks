/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* beforeHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    beforeHead->next = head;
    struct ListNode* current = head;
    struct ListNode* currentNext = head->next;
    struct ListNode* tmp = beforeHead;
    int number = 0;
    while (current) {
        number++;
        current = current->next;
    }
    while (number >= k) {
        current = tmp->next;
        currentNext = current->next;
        for (int i = 1; i < k; ++i) {
            current->next = currentNext->next;
            currentNext->next = tmp->next;
            tmp->next = currentNext;
            currentNext = current->next;
        }
        tmp = current;
        number-=k;
    }
    return beforeHead->next;
}