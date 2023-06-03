/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    for(const ele of arr) {
        if(Array.isArray(ele)) {
            yield* inorderTraversal(ele);
        } else {
            yield ele;
        }
    }

};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */