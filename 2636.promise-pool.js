/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function (functions, n) {
    return new Promise((resolve) => {
        let count = 0;
        let fn_idx = 0;
        function helper() {
            if (fn_idx >= functions.length) {
                if (count === 0) resolve();
                return;
            }
            while (count < n && fn_idx < functions.length) {
                count++;
                const promise = functions[fn_idx]();
                fn_idx++;
                promise.then(() => {
                    count--;
                    helper();
                })
            }
        }
        helper();
    })
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */