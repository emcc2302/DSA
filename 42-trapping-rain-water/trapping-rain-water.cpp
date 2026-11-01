//TLE

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n= height.size();

       
//          int total=0;

//          for(int i=-0;i<n;i++){
//              int leftMost=0;
//              int rightMost=0;
//             //left most
//             for(int j=0;j<=i;j++){
//                 leftMost=max(leftMost,height[j]);
//             }

//             //right most

//             for(int j=i;j<n;j++){
//                 rightMost=max(rightMost,height[j]);
//             }

//             int water = min(leftMost, rightMost) - height[i];

//             total += water;
//          }
//          return total;
//     }
// };



//TWO POINTER
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left=0;
        int right= n-1;

        int leftMost=0;
        int rightMost=0;
        int total=0;

        while(left<right){
            if(height[left]<height[right]){
                
                if(height[left]>=leftMost){
                    leftMost=height[left];
                }
                else{
                    total+=leftMost-height[left];
                }
                left++;
            }else{
                if(height[right]>=rightMost){
                    rightMost=height[right];
                }else{
                    total+=rightMost-height[right];
                }
                right--;
            }
            
        }
        return total;
    }
};