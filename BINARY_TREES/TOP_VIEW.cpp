class Solution {
  public:

    vector<int> level(Node* root){

        vector<int> ans;

        map<int,int> mpp;

        queue<pair<Node*,int>> q;

        q.push({root,0});

        while(!q.empty()){

            Node* node = q.front().first;
            int dist = q.front().second;

            q.pop();

            if(mpp.find(dist) == mpp.end()){
                mpp[dist] = node->data;
            }

            if(node->left != NULL){
                q.push({node->left, dist-1});
            }

            if(node->right != NULL){
                q.push({node->right, dist+1});
            }
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }

    vector<int> topView(Node *root) {

        if(root == NULL) return {};

        return level(root);
    }
};