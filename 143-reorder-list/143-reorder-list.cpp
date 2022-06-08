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
    
    void insertAtHead(ListNode* &head, int data){
        ListNode* temp = new ListNode(data);

        if(head == NULL){
            head=temp;            
        }
        else{
            temp->next = head;
            head=temp;
        }
    }
    
    void reorderList(ListNode* head) {
        ListNode* head2 = NULL;
        int count=0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            insertAtHead(head2,temp->val);
            temp=temp->next;
        }
        
        ListNode* mergeTemp1 = head;
        ListNode* mergeTemp2 = head2;
        ListNode* Temp1=NULL;
        ListNode* Temp2=NULL;
        while(mergeTemp1!=NULL && mergeTemp2!=NULL){
            
            Temp1 = mergeTemp1->next;
            mergeTemp1->next=mergeTemp2;
            
            Temp2=mergeTemp2->next;
            mergeTemp2->next=Temp1;
            
            mergeTemp1=Temp1;
            mergeTemp2=Temp2;
        }
        
        ListNode* finalptr = head;
        count--;
        while(count--){
            finalptr=finalptr->next;
        }
        finalptr->next=NULL;
    }
};