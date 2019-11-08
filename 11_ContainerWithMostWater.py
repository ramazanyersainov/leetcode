class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxarea = 0
        
        while left < right :
            temp_area = min(height[left], height[right]) * (right - left)
            if ( temp_area > maxarea):
                maxarea = temp_area
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return maxarea
        
            