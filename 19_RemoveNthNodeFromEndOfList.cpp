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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* toDelete = new ListNode(0);
        toDelete->next = head;
        ListNode* current = head;
        
        for (int i = 0; i < n; ++ i)
            current = current->next;
        
        while (current != NULL) {
            current = current->next;
            toDelete = toDelete->next;
        }
        

        ListNode* tmp = toDelete->next;
        if (toDelete->next == head)
            return head->next;
        toDelete->next = (toDelete->next)->next;
        delete tmp;
        
        return head;
    }
};