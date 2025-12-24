class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        int apples = accumulate(a.begin(), a.end(), 0);
        sort(c.begin(),c.end());
        int box = 0, cnt = 0;
        for(int i = c.size()-1; i>=0; i--){
            box += c[i];
            cnt++;
            if(box >= apples){
                break;
            }
        }
        return cnt;
    }
};