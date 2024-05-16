class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
            else {
                auto it = std::lower_bound(temp.begin(), temp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return temp.size(); 
    }
};
