class Solution {
public:
    bool search(vector<int>& nums, int target) {
       for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    } 
};