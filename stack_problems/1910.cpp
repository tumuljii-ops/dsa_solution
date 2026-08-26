class Solution {
public:
    string removeOccurrences(string s, string part) {
           
             
              int n=s.length();

              int n1=part.length();

              string result="";

              for(int i=0;i<n;i++){
                 
                   result.push_back(s[i]);

                   if(result.length()>=n1){

                      if(result.substr(result.length()-n1)==part){
                     
                           result.erase(result.length()-n1);
                   }

                   }
                   
              }

              return result;
    }
};