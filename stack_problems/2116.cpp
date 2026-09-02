class Solution {
public:
    bool canBeValid(string s, string locked) {
          
           int n=s.length();

           if(n%2==1) return false;

           stack<int>open_close;

           stack<int>fix;

           for(int i=0;i<n;i++){
             
                if(s[i]=='(' && locked[i]=='1'){
                      fix.push(i);
                }
                else if(locked[i]=='0'){
                     open_close.push(i);
                }
                else if(locked[i]=='1' && s[i]==')'){
                       
                        if(!fix.empty()){
                              fix.pop();
                        }
                        else if(!open_close.empty() && open_close.top()<i){
                                open_close.pop();
                        }
                        else{
                             return false;
                        }
                }
           }

           if(fix.empty() && open_close.size()%2==0){
               return true;
           }

           bool ans=true;

           while(!fix.empty() && !open_close.empty()){
                 
                  if(open_close.top()>fix.top()){
                         open_close.pop();
                         fix.pop();
                  }
                  else{
                     ans=false;
                     break;
                  }
                    
           }

           if(ans==false){
               return false;
           }


           if(open_close.size()%2==0 && fix.size()==0){
               return true;
           }
           else{
              return false;
           }


    }
};