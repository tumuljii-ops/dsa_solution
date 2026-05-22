class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;

        q.push(root);

        bool left_to_right = true;

        while(!q.empty()){

            int size = q.size();

            vector<int> row(size);

            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();
                q.pop();

                int index;

                if(left_to_right){
                    index = i;
                }
                else{
                    index = size - 1 - i;
                }

                row[index] = node->val;

                if(node->left != NULL){
                    q.push(node->left);
                }

                if(node->right != NULL){
                    q.push(node->right);
                }
            }

            left_to_right = !left_to_right;

            ans.push_back(row);
        }

        return ans;
    }
};