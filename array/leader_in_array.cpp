class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        vector<int>ans(n);
        int maxi=INT_MIN;
        
        for(int i=n-1;i>=0;i--){
              maxi=max(maxi,arr[i]);
              ans[i]=maxi;
               
        }
        
        vector<int>store;
        
        for(int i=0;i<n;i++){
            
             if(arr[i]==ans[i]){
                 store.push_back(arr[i]);
             }
        }
        
        return store;
        
    }
};