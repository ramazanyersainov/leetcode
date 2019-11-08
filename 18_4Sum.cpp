class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> poodle;

        int left, right;

        if (nums.size() < 4)
            return poodle;
        
        for (int i = 0; i < nums.size() - 2 ; ++ i) {
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;
            if (nums[i] > 0 && nums[i] > target)
                break;
            for (int j = i + 1; j < nums.size() - 1; ++ j) {
                if (j > i + 1 && nums[j] == nums[j-1]) 
                    continue;

                left = j + 1;
                right = nums.size() - 1;

                while (left < right) {


                    if ((nums[left] + nums[right] + nums[i] + nums[j]) > target)
                        right --;

                    else if ((nums[left] + nums[right] + nums[i] + nums[j]) < target)
                        left ++;

                    else {
                        vector<int> temp = {nums[i] ,nums[j], nums[left] , nums[right]};

                        if (poodle.size() == 0 || temp != poodle[poodle.size() - 1])
                             poodle.push_back(temp);

                        right --;
                    }
                }
            }
            
        }
        return poodle;
    }
};