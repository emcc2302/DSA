#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double ans=0;
        int n=p.size();
        // brute force all triplets
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++) {
                    auto &a=p[i],&b=p[j],&c=p[k];
                    // shoelace formula area
                    ans=max(ans,0.5*abs(
                        a[0]*(b[1]-c[1])+
                        b[0]*(c[1]-a[1])+
                        c[0]*(a[1]-b[1])
                    ));
                }
        return ans;
    }
};