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
                //firse agar 0 k bd 1 aaya too flase,as leading term must be 1 (given in the question)

                //faltu question 
            }
        }
        return true;
    }
};