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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode **pp = &head, *current = head, *end, *top;
        
        if (k == 1)
            return head;
        while (end = isValid(current, k)) {

            ListNode *pred = current;
            current = current->next;
            pred->next = end->next;
            
            while (current != end) {
                
                ListNode* temp = current->next;
                current->next = pred;
                pred = current;
                current = temp;
                
            }
            top = *pp;
            *pp = end;
            pp = &(top->next);
            end->next = pred;
            current = top->next;
        }
            
            
            
        
        return head;
    }
    
    ListNode* isValid(ListNode* head, int& k) {
        int j;
        for ( j = 1 ; head && j < k; ++ j)
            head = head->next;
        
        if (j < k) {
            return NULL;
        }
        return head;
        
    }
    
};