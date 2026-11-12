class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            bool inc = true, dec = true;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j - 1] && inc) {
                    ans = max(ans, j - i + 1);
                }
                else {
                    inc = false;
                }
                if (nums[j] < nums[j - 1] && dec) {
                    ans = max(ans, j - i + 1);
                }
                else {
                    dec = false;
                }
            }
        }
        return ans;
    }
};
