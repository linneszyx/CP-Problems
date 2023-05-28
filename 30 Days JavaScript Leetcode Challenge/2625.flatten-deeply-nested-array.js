/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
  const stack = [...arr.map(item => [item, n])];
    const result = [];
    while (stack.length) {
        const [item, n] = stack.pop();
        if (Array.isArray(item) && n > 0) {
            stack.push(...item.map(item => [item, n - 1]));
        } else {
            result.push(item);
        }

    }
    return result.reverse();
};