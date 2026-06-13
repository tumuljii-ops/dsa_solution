class Solution {
public:
    
    vector<int> ans;

    void dfs(int curr,int n){

        if(curr>n) return;

        ans.push_back(curr);

        for(int digit=0;digit<=9;digit++){

            long long next = 1LL*curr*10 + digit;

            if(next>n) return;

            dfs(next,n);
        }
    }

    vector<int> lexicalOrder(int n) {

        for(int i=1;i<=9;i++){

            if(i>n) break;

            dfs(i,n);
        }

        return ans;
    }
};