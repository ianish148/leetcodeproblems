#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int first = 0; first < n - 2; first++) {

            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }

            int second = first + 1;
            int third = n - 1;

            while (second < third) {
                long long sum = (long long)nums[first]
                              + nums[second]
                              + nums[third];

                if (sum == 0) {
                    ans.push_back({
                        nums[first],
                        nums[second],
                        nums[third]
                    });

                    second++;
                    third--;

                    while (second < third &&
                           nums[second] == nums[second - 1]) {
                        second++;
                    }

                    while (second < third &&
                           nums[third] == nums[third + 1]) {
                        third--;
                    }
                }
                else if (sum < 0) {
                    second++;
                }
                else {
                    third--;
                }
            }
        }

        return ans;
    }
};