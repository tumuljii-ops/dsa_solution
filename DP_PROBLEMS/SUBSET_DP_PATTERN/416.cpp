class Solution {
public:
    bool memo(vector<vector<int>>&dp,vector<int>&nums,int res,int ind,int target){
           
            if(target==res) return true;

            if(ind>=nums.size() || target>res) return false;

             if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
            
            bool nottake=memo(dp,nums,res,ind+1,target);

            bool take=false;

            if(target+nums[ind]<=res){
                take=memo(dp,nums,res,ind+1,target+nums[ind]);
            }

            return dp[ind][target]=take|nottake;
    }
    bool canPartition(vector<int>& nums) {
             int n=nums.size();
             int sum=0;

             //vector<vector<int>>dp(n,vector<int>(sum,-1));

             for(int i=0;i<n;i++){
                sum=sum+nums[i];
             }

               vector<vector<int>>dp(n,vector<int>(sum,-1));

             if(sum%2==1){
                  return false;
             }
             else{
                return memo(dp,nums,sum/2,0,0);
             }
    }
};