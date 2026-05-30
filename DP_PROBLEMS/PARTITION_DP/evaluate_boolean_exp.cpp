class Solution{
public:

    int dp[205][205][2];

    int solve(int i,int j,int isTrue,string &s)
    {
        if(i>j)
            return 0;

        if(i==j)
        {
            if(isTrue)
                return s[i]=='T';

            return s[i]=='F';
        }

        if(dp[i][j][isTrue]!=-1)
            return dp[i][j][isTrue];

        int ways=0;

        for(int k=i+1;k<j;k+=2)
        {
            int LT=solve(i,k-1,1,s);
            int LF=solve(i,k-1,0,s);

            int RT=solve(k+1,j,1,s);
            int RF=solve(k+1,j,0,s);

            if(s[k]=='&')
            {
                if(isTrue)
                    ways += LT*RT;
                else
                    ways += LT*RF + LF*RT + LF*RF;
            }

            else if(s[k]=='|')
            {
                if(isTrue)
                    ways += LT*RT + LT*RF + LF*RT;
                else
                    ways += LF*RF;
            }

            else
            {
                if(isTrue)
                    ways += LT*RF + LF*RT;
                else
                    ways += LT*RT + LF*RF;
            }
        }

        return dp[i][j][isTrue]=ways;
    }

    int countWays(string s)
    {
        memset(dp,-1,sizeof(dp));

        return solve(0,s.size()-1,1,s);
    }
};