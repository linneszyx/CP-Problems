/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head) {
      ListNode * slow = head;
      ListNode * fast = head;
      int maxSum = 0;
      while (fast && fast->next)
      {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode * nn,*prev=NULL;
      while(slow){
        nn = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nn;
      }
      while(prev){
        maxSum = max(maxSum,head->val+prev->val);
        head = head->next;
        prev = prev->next;
      }
      return maxSum;
    }
};
// @lc code=end

