/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (true) {
            int min = INT_MAX;
            int minIndex = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr && lists[i]->val < min) {
                    min = lists[i]->val;
                    minIndex = i;
                }
            }
            if (minIndex == -1) {
                break;
            }
            p->next = lists[minIndex];
            p = p->next;
            lists[minIndex] = lists[minIndex]->next;
        }
        return head->next;
    }
};
// @lc code=end

