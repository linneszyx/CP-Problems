/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
    var mp = []
    for (let i = 0; i < arr.length; i++) {
        mp.push(fn(arr[i], i))
    }
    return mp;
};