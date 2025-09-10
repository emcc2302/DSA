class Solution {
public:
    // int findLucky(vector<int>& arr) {
    //     unordered_map<int,int>mp;
    //     int n=arr.size();
    //     int a=-1;
    //     for(int i:arr){
    //         mp[i]++;
    //     }
    //     for(auto i:mp){
    //         if(i.first==i.second){
    //             a=max(a,i.first);
    //         }
    //     }
    //     return a;;
        
    // }


    int findLucky(vector<int>& arr) {
       
        int freq[501] = {0};
        for (int num : arr) {
            freq[num]++;
        }
        int result = -1;
        for (int i = 1; i <= 500; i++) {
            if (freq[i] == i) {
                result = i;
            }
        }

        return result;
    }
};