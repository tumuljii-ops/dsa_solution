class Solution {
public:
    int firstBadVersion(int n) {
        
        long long low = 1;
        long long high = n;
        
        while(low < high){
            
            long long mid = low + (high - low) / 2;
            
            if(isBadVersion(mid)){
                high = mid;   // possible answer
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};
