class Solution {
public:
    int maxFreqSum(string s) {
        int fre[26]={0};
        int v=0,con=0;

        for(char c:s){
            int i=c-'a';
            fre[i]++;

            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ){
                v= max(v,fre[i]);
            }
            else{
                con = max(con,fre[i]);
            }
        }
        return v+con;
    }
};