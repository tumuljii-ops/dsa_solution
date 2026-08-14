class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
          
            vector<int>ans;

            for(int i=0;i<timePoints.size();i++){

                    if(timePoints[i][0]=='0' && timePoints[i][1]=='0' && timePoints[i][3]=='0' && timePoints[i][4]=='0'){

                        ans.push_back(0);
                   }
                   else{
                 
                   string s=timePoints[i];

                   string s1=s.substr(0,2);
                   string s2=s.substr(3,2);

                   int num1=stoi(s1);
                   num1=num1*60;

                   int num2=stoi(s2);

                   int num=num1+num2;

                   ans.push_back(num);
                   }
            }

            sort(ans.begin(),ans.end());

            int maxi=INT_MAX;

            for(int i=1;i<ans.size();i++){
                   
                    if((ans[i]-ans[i-1])<maxi){
                         maxi=(ans[i]-ans[i-1]);
                    }
            }

            int circular = (24 * 60 - ans[ans.size() - 1]) + ans[0];
            if(circular < maxi){
                maxi = circular;
            }

            return maxi;
    }
};