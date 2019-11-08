/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* top = new ListNode(0);
        top->next = head;
        
        ListNode* pred = top;
        ListNode* one = head;
        ListNode* two;
    
        if (!one)
            return head;
        
        while (one->next) {
            two = one->next;
            
            ListNode* temp = two->next;
            two->next = one;
            one->next = temp;
            pred->next = two;
            
            one = one->next;
            if (!one)
                return top->next;
            pred = two->next;
            
        }
        
        return top->next;
    }
};