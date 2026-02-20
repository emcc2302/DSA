class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> pieces;
        int start= 0;
        int count =0;
        for(int i = 0; i< s.size(); i++){
            if( s[i] == '1') count++;
            else count--;

            if(count == 0){
                string inner = makeLargestSpecial(s.substr(start+1, i - start - 1));

                pieces.push_back("1" + inner + "0" );

                start = i+1;
            }
        }

        sort(pieces.begin(), pieces.end(), greater<string>());

        string temp = "";
        for(auto p:pieces){
            temp += p;
        }

        return temp;
        
    }
};