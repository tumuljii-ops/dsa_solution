class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long q = 0; 
        long long typeA = 0, typeB = 0;
        long long F = flipCost, W = swapCost, C = crossCost;
        
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='0' && t[i]=='1') typeA++;
            else if(s[i]=='1' && t[i]=='0') typeB++;
        }
        
        long long pairs = min(typeA, typeB);
        long long remaining = abs(typeA - typeB);
        
        long long pairCost = pairs * min(2 * F, W);
        
        long long halfCost = (remaining / 2) * min(2 * F, W + C);
        
        long long oddCost = (remaining % 2) * F;
        
        return pairCost + halfCost + oddCost;
    }
};