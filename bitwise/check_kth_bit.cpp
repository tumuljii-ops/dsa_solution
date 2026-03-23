class Solution {
  public:
    bool checkKthBit(int n, int k) {
        
        bool ans=true;
        
        if((n>>k)&1==ans)return true;
        else return false;
        
    }
};