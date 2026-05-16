class Solution {
  public:
   
    bool possible(vector<int>&arr,int k,int mid){
          
           int time=0;
           
           int painter=1;
           
           for(int i=0;i<arr.size();i++){
               
               if(arr[i]>mid) return false;
               
               if(time+arr[i]<=mid){
                    time+=arr[i];
               }
               else{
                   time=arr[i];
                   
                   painter++;
               }
           }
           
           return painter<=k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
           
           int low=*max_element(arr.begin(),arr.end());
           
           int high=accumulate(arr.begin(),arr.end(),0);
           
           int ans=-1;
           
           while(low<=high){
                int mid=(low+high)/2;
                
                
                if(possible(arr,k,mid)){
                    ans=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
           }
           
           return ans;
    }
};