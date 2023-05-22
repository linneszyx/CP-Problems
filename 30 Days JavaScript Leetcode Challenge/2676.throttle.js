/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function (fn, t) {
    var prev = -1;
    var time = null;
    return function (...args) {
        var ct = Date.now();
        if (ct - prev >= t) {
            fn(...args);
            prev = ct;
        }
        else {
            clearTimeout(time);
            time = setTimeout(() => {
                fn(...args);
                time = null;
                prev += t;
            }, prev + t - ct);
        }
    }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */