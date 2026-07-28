class RecentCounter {

private:

        queue<int>req;
        
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        req.push(t);
        while(!req.empty() && req.front()<t-3000){
            req.pop();
        }
        return req.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */