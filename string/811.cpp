class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
             
              unordered_map<string,int>mpp;
              int n=cpdomains.size();


              for(int i=0;i<cpdomains.size();i++){
                   
                   string s=cpdomains[i];

                   int j=0;
                   string ans="";

                   while(s[j]!=' '){
                        ans+=s[j];
                        j++;
                   }

                   int num=stoi(ans);
                   j++;

                   string d1=s.substr(j);

                   mpp[d1]+=num;

                   while(j<s.length()){
                       
                       int k=j;

                       while(k<s.length() && s[k]!='.'){
                            k++;
                       }

                       if(k>=s.length()){
                          break;
                       }

                       k++;
                       string d=s.substr(k);
                       mpp[d]+=num;
                       j=k;
                        
                        
                   }
                   
                    
              }

              vector<string>answer;

              for(auto it:mpp){
                  
                   string s=it.first;
                   int num=it.second;

                   string a=to_string(num)+" "+s;

                   answer.push_back(a);
                   
              }

              return answer;


            
    }
};