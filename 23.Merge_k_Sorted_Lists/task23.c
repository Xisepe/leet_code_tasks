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

    return 0;
}
