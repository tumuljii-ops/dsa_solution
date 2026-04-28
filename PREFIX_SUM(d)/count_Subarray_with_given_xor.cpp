class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
           
        int n = arr.size();
        vector<long long> prefix(n);

        prefix[0] = arr[0];

        unordered_map<int,int> mpp;
        mpp[0] = 1;   // important

        long count = 0;

        // check for first element
        if(prefix[0] == k){
            count++;
        }

        mpp[prefix[0]]++;

        for(int i = 1; i < n; i++){
            
            prefix[i] = prefix[i-1] ^ arr[i];

            int x = prefix[i] ^ k;

            if(mpp.find(x) != mpp.end()){
                count += mpp[x];
            }

            mpp[prefix[i]]++;
        }

        return count;
    }
};