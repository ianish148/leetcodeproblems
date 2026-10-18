class Solution {
    static constexpr int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long dfs(const vector<int>& arr) {
        int m = arr.size();
        if (m <= 2) return 1;

        int root = arr[0];
        vector<int> left, right;
        left.reserve(m);
        right.reserve(m);

        for (int i = 1; i < m; ++i) {
            if (arr[i] < root) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        int l = left.size();
        int r = right.size();

        long long ways = (comb[l + r][l] * dfs(left)) % MOD;
        ways = (ways * dfs(right)) % MOD;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};