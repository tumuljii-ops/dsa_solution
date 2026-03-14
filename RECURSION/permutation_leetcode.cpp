class Solution {
public:
    void permutation(vector<int>&nums,int ind,vector<int>&ans,vector<vector<int>>&store){
        
        if(ind==ans.size()){
            store.push_back(ans);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(ans[ind],ans[i]);
            permutation(nums,ind+1,ans,store);
            swap(ans[ind],ans[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        ans=nums;

        vector<vector<int>>store;
        permutation(nums,0,ans,store);

        return store;
    }
};