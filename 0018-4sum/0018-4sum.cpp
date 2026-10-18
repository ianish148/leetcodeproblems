class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            long long minSumI = (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (minSumI > target) break;
            long long maxSumI = (long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (maxSumI < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long minSumJ = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (minSumJ > target) break;
                long long maxSumJ = (long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (maxSumJ < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};