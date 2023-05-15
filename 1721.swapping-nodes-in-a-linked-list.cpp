/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        int first = k, second = len - k + 1;
        if(first == second) return head;
        ListNode * firstNode = NULL, * secondNode = NULL;
        temp = head;
        int i = 1;
        while(temp){
            if(i == first) firstNode = temp;
            if(i == second) secondNode = temp;
            temp = temp->next;
            i++;
        }
        swap(firstNode->val, secondNode->val);
        return head;
    }
};
// @lc code=end

