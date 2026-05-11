class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        unordered_map<int, vector<pair<int,int>>> mpp;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int prod = nums[i] * nums[j];

                mpp[prod].push_back({i, j});
            }
        }

        int count = 0;
        
        for(auto it : mpp) {

            vector<pair<int,int>> temp = it.second;

            int sz = temp.size();

            for(int i = 0; i < sz; i++) {

                for(int j = i + 1; j < sz; j++) {

                    int a = temp[i].first;
                    int b = temp[i].second;

                    int c = temp[j].first;
                    int d = temp[j].second;
                    
                    if(a != c && a != d &&
                       b != c && b != d) {

                        count += 8;
                    }
                }
            }
        }

        return count;
    }
};