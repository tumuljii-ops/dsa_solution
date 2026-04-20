class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> ans;

        // find repeating
        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i-1]){
                ans.push_back(arr[i]);
                break;
            }
        }

        // mark presence
        vector<bool> anss(n + 1, false);

        for(int i = 0; i < n; i++){
            anss[arr[i]] = true;
        }

        // find missing
        for(int i = 1; i <= n; i++){
            if(anss[i] == false){
                ans.push_back(i);  
                break;
            }
        }

        return ans;
    }
};
