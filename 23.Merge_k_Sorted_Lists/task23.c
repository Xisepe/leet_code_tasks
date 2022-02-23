#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize < 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];
    struct ListNode *head;
    struct ListNode *result = NULL;
    struct ListNode *p_left = mergeKLists(&lists[0], listsSize / 2);
    struct ListNode *p_right = mergeKLists(&lists[listsSize / 2], listsSize - listsSize / 2);

    while (p_left || p_right) {
        if (result == NULL) {
            result = (struct ListNode *) malloc(sizeof(struct ListNode));
            head = result;
        } else {
            result->next = (struct ListNode *) malloc(sizeof(struct ListNode));
            result = result->next;
        }
        int left = INT_MAX, right = INT_MAX;
        if (p_left) {
            left = p_left->val;
        }
        if (p_right) {
            right = p_right->val;
        }
        if (left < right) {
            result->val = left;
            p_left = p_left->next;
        } else {
            result->val = right;
            p_right = p_right->next;
        }
        result->next = NULL;
    }

    return head;
}

int main() {

    struct ListNode **lists = (struct ListNode **) malloc(sizeof(struct ListNode *) * 3);
    lists[0] = (struct ListNode *) malloc(sizeof(struct ListNode));
    lists[0]->val = 1;
    lists[0]->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    lists[0]->next->val = 4;
    lists[0]->next->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    lists[0]->next->next->val = 5;
    lists[0]->next->next->next = NULL;

    lists[1] = (struct ListNode *) malloc(sizeof(struct ListNode));
    lists[1]->val = 1;
    lists[1]->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    lists[1]->next->val = 3;
    lists[1]->next->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    lists[1]->next->next->val = 4;
    lists[1]->next->next->next = NULL;

    lists[2] = (struct ListNode *) malloc(sizeof(struct ListNode));
    lists[2]->val = 2;
    lists[2]->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    lists[2]->next->val = 6;
    lists[2]->next->next = NULL;

    struct ListNode *r = mergeKLists(lists, 3);

    printf("%d", r->val);

    return 0;
}