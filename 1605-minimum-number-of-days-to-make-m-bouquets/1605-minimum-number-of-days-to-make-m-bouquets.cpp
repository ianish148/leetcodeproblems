class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        int consecutive = 0;
        int bouquets = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = (int)bloomDay.size();
        if ((long long)m * k > n) {
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
