class Solution {
public:
    string minWindow(string s, string t) {
         
          if(s.length()<t.length()){
               return "";
          }

          vector<int>visited1(128,0);
          vector<int>visited2(128,0);

          for(int i=0;i<t.length();i++){
             
                visited1[t[i]]++;
          }

          int required=0;

          for(int i=0;i<128;i++){
                 if(visited1[i]>0){
                    required++;
                 }
          }

          int left=0;
          int right=0;
          int start_index=-1;
          int max_len=INT_MAX;

          int formed=0;

          while(right<s.length()){
             
                char ch=s[right];
                visited2[ch]++;

                if(visited1[ch]>0 && visited1[ch]==visited2[ch]){
                       formed++;
                }

                while(left<=right && formed==required){
                         
                        int len=right-left+1;

                        if(len<max_len){
                            max_len=len;
                            start_index=left;
                        }

                        char ch=s[left];

                        visited2[ch]--;

                        if(visited2[ch]<visited1[ch] && visited1[ch]>0){
                              formed--;
                        }

                        left++;
                         
                }

                right++;
          }


         if(start_index==-1){
             return "";
         }
         else{
             return s.substr(start_index,max_len);
         }

    }
};