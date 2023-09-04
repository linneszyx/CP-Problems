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
    bool hasCycle(ListNode *head) {
        ListNode *s = head;
        ListNode *e = head;
        while(e and e->next){
            s = s->next;
            e = e->next->next;
            if(s == e) return true;
        }
        return false;
    }
};