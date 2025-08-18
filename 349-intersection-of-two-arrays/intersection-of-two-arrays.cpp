// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  
//         unordered_map<int, int> freq;
//        unordered_map<vector<int>,int>res;
//         for (int num : nums1) {
//             freq[num]++;
//         }

//         for (int num : nums2) {
//             if (freq[num]>=1) {
//                 res.push_back(num);
//                 freq[num]--;
                
//             }
//         }

//         return res;

//     }
// };


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> freq(nums1.begin(), nums1.end()); 
        unordered_set<int> res; // to avoid duplicates

        for (int num : nums2) {
            if (freq.count(num)) {
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end()); // convert set to vector
    }
};
