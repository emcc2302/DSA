/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    const [value1,value2]=await Promise.all([promise1, promise2]);
    //We use Promise.all to run multiple promises concurrently and wait for all of them.

    //and we use [] bcz promise take only one iterate ,so for 2 iterate we must need an array 
    return (value1+value2);
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */