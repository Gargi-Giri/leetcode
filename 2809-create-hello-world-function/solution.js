/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const greet="Hello World";
    return function(...args) {
        return greet;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
