class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // Calculate width and height
            int width = right - left;
            int h = min(height[left], height[right]);
            
            // Calculate current area and update max_water
            int current_area = width * h;
            max_water = max(max_water, current_area);
            
            // Move the pointer of the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};