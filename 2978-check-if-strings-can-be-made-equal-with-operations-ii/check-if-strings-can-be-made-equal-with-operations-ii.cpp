class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string s1even="", s1odd="";
        string s2even="", s2odd="";

        for(int i=0;i<n;i++)
        {
            //separate based on index parity
            if(!(i&1)){
                s1even+=s1[i];
                s2even+=s2[i];
            }else{
                s1odd+=s1[i];
                s2odd+=s2[i];
            }
        }

        //sort both groups
        sort(s1even.begin(),s1even.end());
        sort(s2even.begin(),s2even.end());
        sort(s1odd.begin(),s1odd.end());
        sort(s2odd.begin(),s2odd.end());

        //compare
        return (s1even==s2even && s1odd==s2odd);
    }
};