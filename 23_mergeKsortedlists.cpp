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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;
        while (interval < amount) {
            for (int i = 0; i<amount-interval; i=i+interval * 2)
                lists[i] = mergeTwoLists(lists[i],lists[i+ interval]);
            interval *= 2;
        }
        if (amount > 0)
            return lists[0];
        else
            return NULL;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* top;
        
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        
        if (l1->val > l2->val) {
            head = l2;
            l2 = l2->next;
        }
        else {
            head = l1;
            l1 = l1->next;
        }
        
        top = head;
        
        while (l1 != NULL && l2 != NULL) {
            
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
            
        }
        
        if (l1 != NULL)
            head->next = l1;
        else if (l2 != NULL)
            head->next = l2;
        
        return top;
    }
};