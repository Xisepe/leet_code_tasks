#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *root = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *cp_l1 = l1;
    struct ListNode *cp_l2 = l2;
    int extra = 0;
    while (cp_l1 != NULL || cp_l2 != NULL || extra != 0) {
        if (tmp == NULL) {
            tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        } else {
            tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
        int sum = 0;
        if (cp_l1 != NULL) {
            sum += cp_l1->val;
            cp_l1 = cp_l1->next;
        }
        if (cp_l2 != NULL) {
            sum += cp_l2->val;
            cp_l2 = cp_l2->next;
        }
        sum += extra;
        extra = sum/10;
        tmp->val = sum % 10;
        tmp->next = NULL;
        if (root == NULL) {
            root = tmp;
        }

    }
    return root;
}

int main() {

    return 0;
}
