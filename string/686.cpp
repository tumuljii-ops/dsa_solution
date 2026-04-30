class Solution {
public:
    int repeatedStringMatch(string a, string b) {
             
             string ans=a;
             int count=1;

             while(ans.length()<b.length()){
                  ans=ans+a;
                  count++;
             }

             if(ans.find(b)!=string::npos){
                    return count;
             }

             ans=ans+a;
             count++;

             if(ans.find(b)!=string::npos){
                  return count;
             }


             return -1;
    }
};