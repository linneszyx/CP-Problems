/**
 * @param {Array} arr
 * @return {Matrix}
 */
var jsonToMatrix = function (arr) {
    const flatterObject = (obj, prefix = "") => {
        let result = {};
        for (let key in obj) {
            let value = obj[key];
            if (typeof value === "object" && value !== null) {
                result = { ...result, ...flatterObject(value, prefix + key + ".") };
            }
            else {
                result[prefix + key] = value;
            }
        }
        return result;
    }
    let flattedArr = arr.map(obj => flatterObject(obj));
    let columnSet = new Set();
    flattedArr.forEach(obj => {
        Object.keys(obj).forEach(key => columnSet.add(key));
    });
    let columns = Array.from(columnSet).sort();
    let matrix = [columns];
    flattedArr.forEach(obj => {
        let row = columns.map(key => (obj[key] !== undefined ? obj[key] : ""));
        matrix.push(row);
    }
    );
    return matrix;
};