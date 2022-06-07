// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int count0 = 0,count1 = 0, count2 = 0;
        
        Node* ptr = head;
        while(ptr!=NULL){
            if(ptr->data == 0){
                count0++;
            }
            else if(ptr->data == 1){
                count1++;
            }
            else{
                count2++;
            }
            ptr=ptr->next;
        }
        
        ptr=head;
        
        while(ptr!=NULL && count0>0){
            ptr->data = 0;
            ptr=ptr->next;
            count0--;
        }
        while(ptr!=NULL && count1>0){
            ptr->data = 1;
            ptr=ptr->next;
            count1--;
        }
        while(ptr!=NULL && count2>0){
            ptr->data = 2;
            ptr=ptr->next;
            count2--;
        }
        return head;   
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends