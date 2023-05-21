/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function (o1, o2) {
    if (typeof o1 !== typeof o2) return false;
    if (typeof o2 !== 'object' || o1 === null || o2 === null) return o1 === o2;
    if (Array.isArray(o1) !== Array.isArray(o2)) return false;
    const k1 = Object.keys(o1).sort();
    const k2 = Object.keys(o2).sort();
    if (k1.length !== k2.length) return false;
    for (let i = 0, len = k1.length; i < len; i++) {
        const ke1 = k1[i];
        const ke2 = k2[i];
        if (ke1 !== ke2) return false;
        const v1 = o1[ke1];
        const v2 = o2[ke2];
        if (!areDeeplyEqual(v1, v2)) return false;
    }
    return true;
};