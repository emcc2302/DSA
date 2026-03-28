class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans(n,0);
        char ch='a';
        for(int i=0;i<n;i++){
            if(ans[i]!=0)continue;
            if(ch>'z')return "";
            for(int j=i;j<n;j++){
                if(lcp[i][j])ans[j]=ch;
            }
            ch++;
        }
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(ans[i]==ans[j])mat[i][j]=mat[i+1][j+1]+1;
                else mat[i][j]=0;
                if(mat[i][j]!=lcp[i][j])return "";
            }
        }
        return ans;
    }
};