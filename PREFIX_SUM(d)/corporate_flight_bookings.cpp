class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
         vector<int>ans(n,0);
         
         for(int i=0;i<bookings.size();i++){
              int label1=bookings[i][0]-1;
              int label2=bookings[i][1]-1;
              
              for(int j=label1;j<=label2;j++){
                  ans[j]=ans[j]+bookings[i][2];
              }

         }

         return ans;

    }
};