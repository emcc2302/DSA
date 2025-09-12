class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCount = count_if(s.begin(), s.end(), [](char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
});
return vowelCount > 0;


        
    }
};