class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
           
               int n1=nums1.size();
               int n2=nums2.size();

               int i=0;
               int j=0;

               int maxi=0;

               while(i<n1 && j<n2){
                  
                    if(nums2[j]>=nums1[i]){

                          maxi=max(maxi,j-i);
                          j++;
                    }
                    else{
                         i++;
                         j++;
                    }

               }

               return maxi;
    }
};