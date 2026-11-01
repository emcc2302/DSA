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