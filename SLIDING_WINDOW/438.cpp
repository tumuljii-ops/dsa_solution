class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
            
            int n1=s.length();
            int n2=p.length();

            int l=0;
            int r=0;

            vector<int>freq1(26);
            vector<int>freq2(26);

            for(int i=0;i<p.length();i++){
                 freq2[p[i]-'a']++;
            }

            vector<int>ans;

            while(r<n1){
                 
                 freq1[s[r]-'a']++;

                 while((r-l+1)>n2){
                      freq1[s[l]-'a']--;
                      l++;
                 }


                 if(freq1==freq2 && (r-l+1)==n2){
                      
                      ans.push_back(l);
                 }



                 r++;
                 
            }

            return ans;
    }
};