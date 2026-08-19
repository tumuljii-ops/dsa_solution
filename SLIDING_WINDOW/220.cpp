class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
          
            vector<pair<long long,int>>vec;

            for(int i=0;i<nums.size();i++){
                  vec.push_back({nums[i],i});
            }

            sort(vec.begin(),vec.end());

            set<int>st;

            int left=0;
            int right=0;

            int n=nums.size();

            while(right<n){
                 
                while(vec[right].first-vec[left].first>valueDiff){
                       st.erase(vec[left].second);
                       left++;
                 }

                 int ind=vec[right].second;

                 auto it=st.lower_bound(ind-indexDiff);

                 if(it!=st.end() && *it<=ind+indexDiff){
                     return true;
                 }

                 st.insert(ind);
                 right++;
            }

            return false;
    }
};