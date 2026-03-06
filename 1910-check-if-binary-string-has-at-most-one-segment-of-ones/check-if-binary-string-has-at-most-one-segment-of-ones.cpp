class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zero=false;

        for(char x :s){
            if(x=='0'){
                zero=true;
            }
            else{
                if(zero) return false;
            }
        }
        return true;
    }
};