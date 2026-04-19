// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> a;
//         vector<int> b;

//         for (int i = 0; i < m; i++) {
//             a.push_back(nums1[i]);
//         }

//         for (int i = 0; i < n; i++) {
//             b.push_back(nums2[i]);
//         }

//         a.insert(a.end(), b.begin(), b.end()); // Merge b into a
//         sort(a.begin(), a.end()); // Sort merged array

//         // Copy back the sorted values into nums1
//         for (int i = 0; i < m + n; i++) {
//             nums1[i] = a[i];
//         }
//     }
// };



//APPROACH 2


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1; 
        int k = m + n - 1; 

       
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

      
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
