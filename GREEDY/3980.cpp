class Solution {
public:
    int minOperations(string s1, string s2) {

          int n1=s1.length();
          int ops=0;

          if(n1==1){
               if(s1[0]==s2[0]) return 0;
               if(s1[0]=='0' && s2[0]=='1') return 1;

              return -1;
          }

         // int ops=0;

          for(int i=0;i<n1;i++){

               if(s1[i]==s2[i]){
                   continue;
               }

               if(s1[i]=='0' && s2[i]=='1'){
                    ops++;
               }
              else if(s1[i]=='1' && s2[i]=='0'){

                    if(i+1<n1 && s1[i+1]=='1' && s2[i+1]=='0'){
                        ops++;
                        i++;
                    }
                  else{


                      ops+=2;
                  }
              }
          }

        return ops;
    }
};