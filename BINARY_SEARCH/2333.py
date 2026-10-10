class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:

        diff=[abs(a-b) for a,b in zip(nums1,nums2)]

        total_bud=k1+k2

        total=sum(diff)

        if total<=total_bud:
            return 0

        
        low=0
        high=max(diff)
        best_diff=high

        while low<=high:
            mid=(low+high)//2

            can_do=sum(max(0,d-mid) for d in diff)

            if can_do<=total_bud:
                best_diff=mid
                high=mid-1
            else:
                low=mid+1

        
        new_diff=[]

        for i in range(len(diff)):

            if diff[i]>best_diff:
                new_diff.append(best_diff)
                total_bud=total_bud-(diff[i]-best_diff)
            else:
                new_diff.append(diff[i])

        for i in range(len(new_diff)):

            if new_diff[i]==best_diff and total_bud>0 and best_diff>0:
                new_diff[i]=new_diff[i]-1
                total_bud=total_bud-1

        return sum(d*d for d in new_diff)

            
        