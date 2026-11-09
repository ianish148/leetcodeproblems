class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap) {
        int day = 1, load = 0;
        for (int w : weights) {
            if (load + w > cap) {
                day++;
                load = 0;
            }
            load += w;
        }
        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};