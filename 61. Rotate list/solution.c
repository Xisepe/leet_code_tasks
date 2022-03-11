//
// Created by maxim on 11.03.2022.
//

#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (!head)
        return head;
    int size = 1;

    struct ListNode *current = head;

    for (; current->next; size++, current = current->next);

    current->next = head;

    struct ListNode *prehead = (struct ListNode *) malloc(sizeof(struct ListNode));
    prehead->next = head;

    if (k %= size) {
        for (int i = 0; i < size - k; i++) {
            current = current->next;
        }
    }
    prehead->next = current->next;
    current->next = NULL;

    return prehead->next;
}
