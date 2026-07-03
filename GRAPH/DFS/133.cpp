class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {

        if(node == NULL)
            return NULL;

        // Already cloned
        if(mp.count(node))
            return mp[node];

        // Create clone
        Node* clone = new Node(node->val);

        // Store before visiting neighbours
        mp[node] = clone;

        // Clone neighbours
        for(Node* nbr : node->neighbors) {

            clone->neighbors.push_back(dfs(nbr));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {

        return dfs(node);
    }
};