class Solution {
public:
    void permutation(vector<vector<int>>&store,vector<bool>&visited,vector<int>&nums,vector<int>&perm){
            
             if(perm.size()==nums.size()){
                store.push_back(perm);
                return;
             }

             for(int i=0;i<nums.size();i++){
                   
                   if(visited[i]==true) continue;

                   perm.push_back(nums[i]);
                   visited[i]=true;
                   permutation(store,visited,nums,perm);
                   perm.pop_back();
                   visited[i]=false;
                   
             }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();

        vector<int>perm;
        vector<bool>visited(n,false);
        vector<vector<int>>store;

        permutation(store,visited,nums,perm);

        return store;

    }
};