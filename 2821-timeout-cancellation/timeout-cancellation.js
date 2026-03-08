var cancellable = function(fn, args, t) {
    // call setTimeout, which is set to call fn after t amount of time
    var timeout = setTimeout(() =>
        fn(...args)
    , t)

    // define a clearTimeout
    var cancelFn = () => clearTimeout(timeout);

    // When/if we call the function, it will return cancelFn,
    // and since the return line calls (and consequentially executes)
    // cancelFn, timeout will be cancelled, thereby cancelling fn
    return cancelFn;
};