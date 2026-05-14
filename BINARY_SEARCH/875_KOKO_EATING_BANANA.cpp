class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
         while (low <= high) {
         int mid = (low + high) / 2;
            long long hours = countHours(piles, mid);
            if (hours <= h) {
                ans = mid;      
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }

        return ans;
    }

private:
    long long countHours(vector<int>& piles, int speed) {
        long long total = 0;
        for (int bananas : piles) {
            total += (bananas + speed - 1) / speed; 
        }
        return total;
    }
};
