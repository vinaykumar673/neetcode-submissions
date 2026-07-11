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
    ListNode* deleteNodes(ListNode* head, int m, int n)
    {

        if(!head) return head;

        ListNode* curr = head;

        while(curr)
        {
            int i = m;
            while(i > 1 && curr)
            {
                curr = curr->next;
                i--;
            }

            if(!curr) return head;
            
            ListNode* next = curr->next;
            int j = n;
            while(next && j > 0)
            {
                next = next->next;
                j--;
            }

            curr->next = next;
            curr = next;
        }

        return head;
        
    }
};
