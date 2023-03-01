/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution
{
public:
    void insertion_sort(vector<int> &nums, int left, int right)
    {
        for (int i = left + 1; i <= right; i++)
        {
            int j = i;
            while (j > left && nums[j] < nums[j - 1])
            {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }
    }
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;
        if (right - left + 1 <= 16)
        {
            insertion_sort(nums, left, right);
            return;
        }
        int pivot_index = rand() % (right - left + 1) + left;
        int pivot = nums[pivot_index];
        int i = left, j = right;
        while (i <= j)
        {
            while (nums[i] < pivot)
                i++;
            while (nums[j] > pivot)
                j--;
            if (i <= j)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        quickSort(nums, left, j);
        quickSort(nums, i, right);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        srand(time(0));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
