class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        for (int x : arr) {
            while (num < x) {
                k--;
                if (k == 0)
                    return num;
                num++;
            }
            num++;
        }
        return num + k - 1;
    }
};