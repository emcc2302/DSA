var cancellable = function(fn, args, t) {
    // Call immediately (time = 0ms)
    fn(...args);

    // Call repeatedly every t milliseconds
    const timer = setInterval(() => {
        fn(...args);
    }, t);

    // Cancel function stops the interval
    const cancelFn = () => {
        clearInterval(timer);
    };

    return cancelFn;
};