/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    var fi = []
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) {
            fi.push(arr[i]);
        }
    }
    return fi;
};