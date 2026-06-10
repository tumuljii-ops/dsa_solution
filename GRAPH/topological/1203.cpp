class Solution {
public:

    // Standard Kahn's Algorithm for Topological Sort
    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& indegree) {

        queue<int> q;

        // Nodes having indegree 0 can be processed first
        for(int i = 0; i < adj.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            // Remove outgoing edges
            for(int nxt : adj[node]) {

                indegree[nxt]--;

                if(indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        // If cycle exists, topological ordering is impossible
        if(topo.size() != adj.size()) {
            return {};
        }

        return topo;
    }

    vector<int> sortItems(int n, int m,
                          vector<int>& group,
                          vector<vector<int>>& beforeItems) {

        /*
            STEP 1:
            Give every item with group = -1 its own unique group.

            Why?

            Topological sorting on groups becomes much easier if
            every item belongs to exactly one group.
        */
        int newGroupId = m;

        for(int i = 0; i < n; i++) {
            if(group[i] == -1) {
                group[i] = newGroupId++;
            }
        }

        /*
            Item Graph:
            item u -> item v
            means u must come before v
        */
        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n, 0);

        /*
            Group Graph:
            group A -> group B

            means some item in A must come before
            some item in B
        */
        vector<vector<int>> groupGraph(newGroupId);
        vector<int> groupIndegree(newGroupId, 0);

        /*
            STEP 2:
            Build both graphs simultaneously.
        */
        for(int item = 0; item < n; item++) {

            for(int prev : beforeItems[item]) {

                //----------------------------------
                // Build item dependency graph
                //----------------------------------

                itemGraph[prev].push_back(item);
                itemIndegree[item]++;

                //----------------------------------
                // Build group dependency graph
                //----------------------------------

                int groupPrev = group[prev];
                int groupCurr = group[item];

                /*
                    If both items belong to same group,
                    group ordering is not affected.

                    Example:
                    A -> A

                    No need to add group edge.
                */
                if(groupPrev != groupCurr) {

                    groupGraph[groupPrev].push_back(groupCurr);
                    groupIndegree[groupCurr]++;
                }
            }
        }

        /*
            STEP 3:
            Topological order of items.
        */
        vector<int> itemOrder =
            topoSort(itemGraph, itemIndegree);

        if(itemOrder.empty()) {
            return {};
        }

        /*
            STEP 4:
            Topological order of groups.
        */
        vector<int> groupOrder =
            topoSort(groupGraph, groupIndegree);

        if(groupOrder.empty()) {
            return {};
        }

        /*
            STEP 5:

            Put items into buckets according to
            item topological order.

            Why?

            Because itemOrder already respects
            all item dependencies.

            Example:

            itemOrder = [6,0,3,1,4,2]

            Group A -> [0,1,2]
            Group B -> [6,3]
            Group C -> [4]

            Internal ordering is automatically valid.
        */
        vector<vector<int>> itemsInGroup(newGroupId);

        for(int item : itemOrder) {
            itemsInGroup[group[item]].push_back(item);
        }

        /*
            STEP 6:

            Output groups according to group topo order.

            This guarantees:
            - item dependencies satisfied
            - group dependencies satisfied
            - same group remains contiguous
        */
        vector<int> answer;

        for(int grp : groupOrder) {

            for(int item : itemsInGroup[grp]) {
                answer.push_back(item);
            }
        }

        return answer;
    }
};