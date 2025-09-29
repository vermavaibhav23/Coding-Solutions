//19. Remove Nth Node From End of List
//Compiler - C++
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=two-pointers

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalnodes = 0;
        ListNode* temp = head;
        while( temp != NULL) {
            totalnodes++;
            temp = temp -> next;
        }
        if(totalnodes <= 1) return NULL;
        int toreach = totalnodes - n + 1;
        if(toreach == 1) return head->next;
        int nodenum = 0;
        temp = head;
        while(temp != NULL) {
            nodenum++;
            if(nodenum == toreach-1) {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};