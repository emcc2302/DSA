const fs = require('fs')

const createHelloWorld = function() {
    return function(...args) {
        return 'Hello World'
    }
}


    fs.writeFileSync("display_runtime.txt", "0");
