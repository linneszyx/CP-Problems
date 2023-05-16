/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
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
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode * first = cur->next;
            ListNode * second = cur->next->next;
            first->next = second->next;
            second->next = first;
            cur->next = second;
            cur = cur->next->next;
        }
        return dummy->next;
    }
};
// @lc code=end

