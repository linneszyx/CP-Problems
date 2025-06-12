class Solution {
public:
    ListNode* f(ListNode* list1,ListNode* list2) {
      if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* temp = new ListNode(-1);
        ListNode* tail = temp;
        while(list1!=NULL and list2!=NULL){
            if(list1->val < list2->val) {
                    tail->next = list1;
                    list1= list1->next;
            }
            else {
                    tail->next = list2;
                    list2= list2->next;
            }
            tail = tail->next;
        }
        if(list1!=NULL) tail->next = list1;
        if(list2!=NULL) tail->next = list2;
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        ListNode* pp = lists[0];
        for(int i=1;i<n;i+=1) {
            pp = f(pp,lists[i]);
        }
        return pp;
    }
};