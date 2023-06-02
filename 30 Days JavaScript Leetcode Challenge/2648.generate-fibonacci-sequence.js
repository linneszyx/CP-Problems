/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let p = 0;
    let c = 1;
    while (true) {
        yield p;
        [p, c] = [c, p + c];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */