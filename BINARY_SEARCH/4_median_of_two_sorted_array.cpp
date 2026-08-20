class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
             
             // always median on small array
              if(nums1.size()>nums2.size()){
                 
                   return findMedianSortedArrays(nums2,nums1);
              }

              int low=0;
              int high=nums1.size();
              int n1=nums1.size();
              int n2=nums2.size();

              while(low<=high){
                 
                   int cnt1=(low+high)/2;
                   int cnt2=(n1+n2+1)/2-cnt1;

                   int l1;

                   if(cnt1==0){
                      l1=INT_MIN;
                   }
                   else{
                      l1=nums1[cnt1-1];
                   }

                   int l2;

                   if(cnt2==0){
                       l2=INT_MIN;
                   }
                   else{
                      l2=nums2[cnt2-1];
                   }

                   int r1;

                   if(cnt1==n1){
                        r1=INT_MAX;
                   }
                   else{
                      r1=nums1[cnt1];
                   }

                   int r2;

                   if(cnt2==n2){
                       r2=INT_MAX;
                   }
                   else{
                      r2=nums2[cnt2];
                   }

                   if(l1<=r2 && l2<=r1){
                     
                          if((n1+n2)%2==1){
                             
                               return max(l1,l2);
                          }
                          else{

                            return  (max(l1,l2)+min(r1,r2))/2.0;
                          }
                   }
                   else if(l1>r2){
                          high=cnt1-1;
                   }
                   else{
                    low=cnt1+1;
                   }
              }

              return 0.0;
    }
};