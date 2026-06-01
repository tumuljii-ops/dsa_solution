class Codec {
public:
    // Encodes a tree to a single string using BFS
    string serialize(TreeNode* root) {
        if (!root) return "";

        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                result += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                result += "#,";
            }
        }

        return result;
    }

    // Decodes your encoded data to tree using BFS
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            // Left child
            if (!getline(ss, token, ',')) break;
            if (token != "#") {
                TreeNode* leftNode = new TreeNode(stoi(token));
                current->left = leftNode;
                q.push(leftNode);
            }

            // Right child
            if (!getline(ss, token, ',')) break;
            if (token != "#") {
                TreeNode* rightNode = new TreeNode(stoi(token));
                current->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};