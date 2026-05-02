class Solution {
public:
    int trap(vector<int>& height) {
       /* int n = height.size();
        if(n == 0) return 0;

        vector<int> prefix(n), suffix(n);
        int total = 0;

        prefix[0] = height[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i-1], height[i]);
        }

        suffix[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = max(suffix[i+1], height[i]);
        }

        for(int i = 0; i < n; i++) {
            int left_max = prefix[i];
            int right_max = suffix[i];

            if(height[i] < left_max && height[i] < right_max) {
                total += min(left_max, right_max) - height[i];
            }
        }

        return total;*/
        
        int l=0;
        int n=height.size();
        int r=n-1;
        
        int leftmax=0;
        int rightmax=0;
        int total=0;

        while(l<r){
              
            leftmax=max(leftmax,height[l]);
            rightmax=max(rightmax,height[r]);

            if(leftmax<rightmax){
                 total=total+(leftmax-height[l]);
                 l++;
            }
            else{
                total=total+(rightmax-height[r]);
                r--;
            }
        }

        return total;

    }
};
