class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
            if(head==NULL or head->next==NULL) return head;
            int sz = 0;
            ListNode* curr = head;
            ListNode* tail = head;
            while(curr!=NULL) {
                sz++;
                tail = curr;
                curr=curr->next;
            }
            k%=sz;
            if(k==0) return head;
            int steps = sz-k-1;
            curr  = head;
            while(steps--) curr = curr->next;
            ListNode* temp = curr->next;
            curr->next = NULL;
            tail->next = head;
            return temp;
          
    }
};