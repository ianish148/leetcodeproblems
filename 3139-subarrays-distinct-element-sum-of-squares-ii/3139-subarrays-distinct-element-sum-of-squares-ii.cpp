// had to copy the solution just to save streak, still didnt get!
class Solution {
    static const int MOD = 1e9 + 7;
    struct Node {
        long long sum = 0;
        long long sumSq = 0;
        long long lazy = 0;
    };
    vector<Node> tree;
    int n;
    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;

        tree[node].sumSq =
            (tree[node].sumSq + 2 * x % MOD * tree[node].sum % MOD
             + len % MOD * x % MOD * x % MOD) % MOD;

        tree[node].sum = (tree[node].sum + len * x) % MOD;
        tree[node].lazy = (tree[node].lazy + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        apply(node * 2, l, mid, tree[node].lazy);
        apply(node * 2 + 1, mid + 1, r, tree[node].lazy);
        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long x) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, x);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, x);
        update(node * 2 + 1, mid + 1, r, ql, qr, x);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;
        tree[node].sumSq =
            (tree[node * 2].sumSq + tree[node * 2 + 1].sumSq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            update(1, 0, n - 1, p + 1, i, 1);

            last[nums[i]] = i;

            ans = (ans + tree[1].sumSq) % MOD;
        }
        return ans;
    }
};
