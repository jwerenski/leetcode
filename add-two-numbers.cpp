struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int sum = 0;
        int carry = 0;

        while(ptr1 && ptr2) {
            sum = ptr1->val + ptr2->val + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            curr = curr->next;
        }

        while(ptr1) {
            sum = ptr1->val + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;

            ptr1 = ptr1->next;
            curr = curr->next;
        }

        while(ptr2) {
            sum = ptr2->val + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;

            ptr2 = ptr2->next;
            curr = curr->next;
        }

        if(sum / 10){
            curr->next = new ListNode(sum / 10);
        }

        return ans->next;
    }
};