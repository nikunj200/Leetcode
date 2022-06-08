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
        ListNode* fast=head;
        ListNode* slow=head;
        
        if(head->next == NULL){
            return NULL;
        }
        
        while(n--){
            fast=fast->next;
        }
        
        if(fast == NULL){
            // shift head
            ListNode* numToDel2 = head;
            head=head->next;
            delete(numToDel2);
            return head;
        }
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* numToDel = slow->next;
        slow->next=slow->next->next;
        delete(numToDel);
        
        return head;
    }
};