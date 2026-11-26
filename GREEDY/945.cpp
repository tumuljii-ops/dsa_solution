class Solution:
    def minIncrementForUnique(self, nums: list[int]) -> int:

        nums=sorted(nums)
        mini=min(nums)

        n=len(nums)

        maxi=max(nums)

        maxi=max(maxi,n)

        visited=[0]*(maxi+mini+1)

        for i in range(len(nums)):

            visited[nums[i]]=1
        

        total=0
        for i in range(1,len(nums)):

            if nums[i]==nums[i-1]:
                j=nums[i]+1

                while j<len(visited):

                    if visited[j]==0:
                        total=total+(j-nums[i])
                        visited[j]=1
                        break
                    j+=1
            else:
                continue
        

        return total





        