class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> dp(k), sum(k);
        for(int i=n-1; i>=n-k; i--) 
            sum[i%k]=dp[i%k]=energy[i];
        
        for(int i=n-k-1; i>=0; i--){
            int iModk=i%k;
            sum[iModk]+=energy[i];
        //    cout<<i<<"->"<<sum[iModk]<<endl;
            dp[iModk]=max(dp[iModk], sum[iModk]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();