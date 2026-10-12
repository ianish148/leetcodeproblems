class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(32, 0);

        for (int num : nums) {
            for (int b = 0; b < 32; b++) {
                if (num & (1 << b)) {
                    cnt[b]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int b = 0; b < 32; b++) {
                if (cnt[b] > 0) {
                    num |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};