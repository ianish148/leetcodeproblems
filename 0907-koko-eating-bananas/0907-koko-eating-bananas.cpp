class Solution {
private:
    bool canFinish(vector<int>& piles, int speed, int h) {
        long long hours = 0;
 
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;
            if (hours > h) {
                return false;
            }
        }
        return hours <= h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canFinish(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};