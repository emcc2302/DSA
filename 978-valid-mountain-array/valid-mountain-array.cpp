// class Solution {
// public:
//     bool validMountainArray(vector<int>& arr) {
//         if(arr.size()<3)return false;
       
//         unordered_map<int,int>x;

//         for(int i=0;i<arr.size();i++){
//             x[arr[i]]++;
//         }

//         for(auto y:x){
//             if(y.second==2) return false;

//         }
//         return true;

//     }
// };

//wrong


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(), i = 0;

        // climb up
        while (i + 1 < n && arr[i] < arr[i + 1]) i++;

        // peak can't be first or last
        if (i == 0 || i == n - 1) return false;

        // climb down
        while (i + 1 < n && arr[i] > arr[i + 1]) i++;

        return i == n - 1;
    }
};
