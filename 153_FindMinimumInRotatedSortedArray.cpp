class Solution {
public:
    int findMin(vector<int>& nums) {
        if (!nums.size())
            return 1;
        if (nums.size() == 1)
            return nums[0];
        
        
        int pivot = nums[0];
        
        int size = nums.size()-1;
        
        int i = 1, j = size;
        
        int half = (i + j) / 2;
        
        while (i <= j && i >= 0 && j < nums.size()) {
            
            if ((half < size && nums[half] < nums[half-1] && nums[half] < nums[half + 1]) || (half == size && nums[half] < nums[half-1]) )
                return nums[half];
            
            else if (nums[half] >= pivot)
                i = half + 1;
            else
                j = half - 1;

            half = (i + j)/2;
            
        }
        
        return pivot;
    }
};