class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int left=0;
        int right=size-1;
        int maxi=-1;
        while(left<right){
            int h=min(height[left],height[right]);
            int w=right-left;
            int area = w * h;
            maxi = max(maxi, area);

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
          
        }
        return maxi;
    }
};