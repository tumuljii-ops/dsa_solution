class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        vector<int>ans(n);

        for(int i=0;i<hours.size();i++){
            if(hours[i]>8){
                ans[i]=1;
            }
            else{
                ans[i]=-1;
            }
        }

        int pre=0;
        int maxi=0;
        unordered_map<int,int>mpp;

        for(int i=0;i<ans.size();i++){
                pre=pre+ans[i];

                if(pre>0) maxi=max(maxi,i+1);

                if(mpp.find(pre-1)!=mpp.end()){
                      maxi=max(maxi,i-mpp[pre-1]);
                }

                if(mpp.find(pre)==mpp.end()){
                    mpp[pre]=i;
                }


        }

        return maxi;
    }
};