/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function (fn) {
  let c = 0;
  return function (...args) {
    c += 1;
    if (c == 1) {
      return fn(...args);
    }
    return undefined;
  }
};

