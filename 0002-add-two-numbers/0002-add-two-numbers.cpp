class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* newhead = new ListNode();
        ListNode* temp = newhead;
        int sum = 0;
        int carry = 0;
        while (ptr1 != NULL || ptr2 != NULL || carry) {
            int x = (ptr1 == NULL) ? 0 : ptr1->val;
            int y = (ptr2 == NULL) ? 0 : ptr2->val;
            int total = x + y + carry;
            sum=total%10;
            carry=total/10;
            temp->val = sum;
            if (ptr1) ptr1 = ptr1->next;
            if (ptr2) ptr2 = ptr2->next;

            if (ptr1 != NULL || ptr2 != NULL || carry) {
                temp->next = new ListNode();
                temp = temp->next;
                temp->next = NULL;
            }
        }
        return newhead;
    }
};