class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        
        priority_queue<int>pq;
        
        priority_queue<int,vector<int>,greater<int>>pq1;
        
        
        vector<double>ans;
        
        if(arr.size()==0) return ans;
        
        ans.push_back(arr[0]);
        pq.push(arr[0]);
        int n=arr.size();
        
        for(int i=1;i<n;i++){
             
              
                if(arr[i]<=pq.top()){
                     pq.push(arr[i]);
                }
                else{
                     pq1.push(arr[i]);
                }
                
                while(pq.size()> pq1.size()+1){
                     
                      int top=pq.top();
                      
                      pq.pop();
                      
                      pq1.push(top);
                }
                
                while(pq1.size()>pq.size()){
                     
                      int top=pq1.top();
                      
                      pq1.pop();
                      
                      pq.push(top);
                }
                
                int x=pq.top();
                
                if(((i+1)%2)==0){
                     int y=pq1.top();
                     
                     double z=(x+y)/2.0;
                     
                     ans.push_back(z);
                     
                }
                else{
                     
                     ans.push_back(0.0+x);
                }
        }
        
        return ans;
        
    }
};
