/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
    var s = init;
    for (let i = 0; i < nums.length; i++) {
        s = fn(s, nums[i]);
    }
    return s;
};