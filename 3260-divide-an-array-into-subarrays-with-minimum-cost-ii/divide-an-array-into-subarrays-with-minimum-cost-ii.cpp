class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans=1e15,temp_sum=0;
        int n=nums.size(),s=n-dist-1; 

        priority_queue<int,vector<int>,greater<int>>maxi;
        priority_queue<int>mini;
        unordered_map<int,int>mp_mini;
        unordered_map<int,int>mp_maxi;
        vector<int>temp;

        for(int i=n-1;i>=s && i>=1;i--) temp.push_back(nums[i]);
        sort(temp.begin(),temp.end());
        for(int i=0;i<k-1;i++){
            temp_sum+=1LL*temp[i];
            mini.push(temp[i]);
        } 
        for(int i=k-1;i<temp.size();i++) maxi.push(temp[i]);

        ans=temp_sum;

        cout<<ans<<" "<<temp_sum;
        cout<<" "<<temp.size();

        for(int i=s-1;i>=1;i--){
            int new_element=nums[i];
            int old_element=nums[i+dist+1];

            while(!mini.empty() && mp_mini[mini.top()]>0){
                mp_mini[mini.top()]--;
                mini.pop();
            }
            while(!maxi.empty() && mp_maxi[maxi.top()]>0){
                mp_maxi[maxi.top()]--;
                maxi.pop();
            }

            if(!maxi.empty() && old_element>=maxi.top()){
                 mp_maxi[old_element]++;

                 if(new_element<mini.top()){
                    maxi.push(mini.top());
                     temp_sum-=1LL*mini.top();
                    mini.pop();
                    mini.push(new_element);
                    temp_sum+=1LL*new_element;
                 }
                 else{
                    maxi.push(new_element);
                 }

            }
            else{
                 mp_mini[old_element]++;
                 temp_sum-=1LL*old_element;

                 if(!maxi.empty() && new_element>maxi.top()){
                    mini.push(maxi.top());
                    temp_sum+=1LL*maxi.top();
                    maxi.pop();
                    maxi.push(new_element);
                 }
                 else{
                    mini.push(new_element);
                     temp_sum+=1LL*new_element;
                 }

            }

            ans=min(ans,temp_sum);

        }
        return ans+1LL*nums[0];
    }
};