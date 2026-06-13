class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells,
                                vector<int>& potions,
                                long long success) {

        sort(potions.begin(), potions.end());

        int m = potions.size();

        vector<int> answer;

        for(int i=0;i<spells.size();i++){

            int low = 0;
            int high = m - 1;

            int firstValid = m;

            while(low <= high){

                int mid = low + (high-low)/2;

                long long product =
                    1LL * spells[i] * potions[mid];

                if(product >= success){
                    firstValid = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            answer.push_back(m - firstValid);
        }

        return answer;
    }
};