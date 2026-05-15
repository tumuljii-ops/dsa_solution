class Solution {
    int f(vector<int>& weights, int mid) {
        int days = 1;  
        int load = 0;
        for (int w : weights) {
            if (load + w > mid) {  
                days++;
                load = 0;
            }
            load += w;
        }
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0); 
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            int requiredDays = f(weights, mid);

            if (requiredDays <= days) {
                ans = mid;        
                high = mid - 1;
            } else {
                low = mid + 1;     
            }
        }
        return ans;
    }
};
