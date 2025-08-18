class Solution {
    const double EPS = 1e-6;
private:
    bool valid(double a, double b){
        return fabs(a + b - 24.0) < EPS | fabs(a - b - 24.0) < EPS | 
                fabs(a * b-24.0) < EPS | fabs(a / b-24.0) < EPS;
    }
    bool valid(double a, double b, double c){
        return valid(a + b, c) | valid(a - b, c) | valid(a * b, c) | valid(a / b, c) | 
                valid(a, b + c) | valid(a, b - c) | valid(a, b * c) | valid(a, b / c);
    }
    bool permutation(int idx, vector<double>& nums){
        if(idx == 4){
            return valid(nums[0] + nums[1], nums[2], nums[3]) |
                    valid(nums[0], nums[1] + nums[2], nums[3]) |
                    valid(nums[0], nums[1], nums[2] + nums[3]) |
                    valid(nums[0] - nums[1], nums[2], nums[3]) |
                    valid(nums[0], nums[1] - nums[2], nums[3]) |
                    valid(nums[0], nums[1], nums[2] - nums[3]) |
                    valid(nums[0] * nums[1], nums[2], nums[3]) |
                    valid(nums[0], nums[1] * nums[2], nums[3]) |
                    valid(nums[0], nums[1], nums[2] * nums[3]) |
                    valid(nums[0] / nums[1], nums[2], nums[3]) |
                    valid(nums[0], nums[1] / nums[2], nums[3]) |
                    valid(nums[0], nums[1], nums[2] / nums[3]);
        }
        int res = false;
        unordered_set<int> s;
        for(int i=idx; i<4 && !res; i++){
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[i], nums[idx]);
            res |= permutation(idx + 1, nums);
            swap(nums[i], nums[idx]);
        }
        return res;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int c: cards) nums.push_back((double)c);
        return permutation(0, nums);
    }
};