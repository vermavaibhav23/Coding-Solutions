//2. Add Two Numbers
//C++
//https://leetcode.com/problems/add-two-numbers/?envType=problem-list-v2&envId=linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* add(ListNode* head, ListNode* b) {
        ListNode* temp = head;
        int carry = 0;
        ListNode* last = NULL;

        while(temp != NULL && b != NULL) {
            temp->val = temp->val + b->val + carry;
            carry = 0;
            if(temp->val > 9) {
                carry = 1;
                temp->val = temp->val % 10;
            }
            b = b->next;
            last = temp;
            temp = temp -> next;
        }
        while(carry > 0 && temp != NULL) {
            temp->val = temp->val + carry;
            carry = 0;
            if(temp->val > 9) {
                carry = 1;
                temp->val = temp->val % 10;
            }
            last = temp;
            temp = temp -> next;
        }
        if(temp == NULL && carry > 0) last->next = new ListNode(1);
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ht1 = getLength(l1);
        int ht2 = getLength(l2);
        if(ht1 >= ht2) {
            return add(l1, l2);
        }
        return add(l2, l1);
    }
};