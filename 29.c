#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    free(slow);

    return head;
}

int main() {
    struct ListNode* n5 = malloc(sizeof(struct ListNode));
    struct ListNode* n4 = malloc(sizeof(struct ListNode));
    struct ListNode* n3 = malloc(sizeof(struct ListNode));
    struct ListNode* n2 = malloc(sizeof(struct ListNode));
    struct ListNode* n1 = malloc(sizeof(struct ListNode));

    n1->val = 1; n1->next = n2;
    n2->val = 2; n2->next = n3;
    n3->val = 3; n3->next = n4;
    n4->val = 4; n4->next = n5;
    n5->val = 5; n5->next = NULL;

    struct ListNode* head = deleteMiddle(n1);

    struct ListNode* curr = head;
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }

    return 0;
}
