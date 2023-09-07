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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         ListNode **pivot = &head, **prev;
    for (int i=0; i<m; i++)
        pivot = &(*(prev=pivot))->next;
    for (int i=m; i<n; i++) {
        swap(*prev, (*pivot)->next);
        swap(*prev, *pivot);
    }
    return head;
    }
};