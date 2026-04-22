class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        
        d = d % n; // important (handles large d)
        
        vector<int> ans(2 * n);
        
        // fill circular array
        for(int i = 0; i < 2 * n; i++) {
            ans[i] = arr[i % n];
        }
        
        // overwrite original array
        for(int i = 0; i < n; i++) {
            arr[i] = ans[i + d];
        }
    }
};
