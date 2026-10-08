class Solution:
    def longIncPath(self, matrix, n, m):
        # code here
        
        dp=[[0]*m for _ in range(n)]
        
        def dfs(row,col,prev_num):
            
            if row<0 or row>=n or col<0 or col>=m:
                return 0
                
            if matrix[row][col]<=prev_num:
                return 0
                
            if dp[row][col]!=0:
                return dp[row][col]
                
            up=dfs(row+1,col,matrix[row][col])
            down=dfs(row-1,col,matrix[row][col])
            left=dfs(row,col+1,matrix[row][col])
            right=dfs(row,col-1,matrix[row][col])
            
            
            dp[row][col]=1+max(up,down,left,right)
            return dp[row][col]
                
        ans=0
        
        for i in range(n):
            for j in range(m):
                ans=max(ans,dfs(i,j,float('-inf')))
                
        return ans
        