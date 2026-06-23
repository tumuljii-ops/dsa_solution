class Solution {
public:
    int maxLevelSum(TreeNode* root) {
           
           queue<TreeNode*>q;

           q.push(root);

           int anslevel=1;
           int level=1;

           long long maxi=LLONG_MIN;

           while(!q.empty()){
                
                 int size=q.size();

                 long long sum=0;

                 for(int i=0;i<size;i++){
                       TreeNode* temp=q.front();
                       q.pop();

                       sum+=temp->val;

                       if(temp->left){
                        q.push(temp->left);
                       }

                       if(temp->right){
                        q.push(temp->right);
                       }


                 }

                 if(sum>maxi){
                    maxi=sum;
                    anslevel=level;
                 }

                 level++;
           }

           return anslevel;
    }
};