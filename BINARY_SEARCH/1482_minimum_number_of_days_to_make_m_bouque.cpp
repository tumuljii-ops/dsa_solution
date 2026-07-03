class Solution {
public:
    bool canmake(vector<int>&bloomDay,int m,int k,int mid){
        int flower=0;
        int bouque=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                flower++;
                if(flower==k){
                    bouque++;
                    flower=0;
                }
            }
            else{
                flower=0;
            }
        }
        return bouque>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total =1LL*m*k;
        int n=bloomDay.size();
        if(total>n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(canmake(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;


    }
};