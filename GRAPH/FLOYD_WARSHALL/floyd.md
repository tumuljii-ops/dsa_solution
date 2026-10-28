/*
================================================================================
⚡ FLOYD-WARSHALL ALGORITHM - QUICK REVISION NOTES (CRUX & INTUITION)
================================================================================

1. WHAT IS IT? (The Core Intuition)
--------------------------------------------------------------------------------
- It is an **All-Pairs Shortest Path** algorithm. 
- Matlab: Yeh ek hi baar mein **sare pairs of nodes** (every node se every other node) ke beech ka shortest distance nikal ke de deta hai.
- Approach: **Dynamic Programming**. Ye poochta hai: 
  "Kya main node 'i' se node 'j' tak jaane ke liye kisi intermediate node 'k' 
   ke through jaun, toh rasta chhota padega?"
- Formula: dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])


2. HOW TO IDENTIFY A FLOYD-WARSHALL PROBLEM?
--------------------------------------------------------------------------------
Look for these keywords and constraints in the problem statement:
- "Find shortest path between **all pairs**" (Not just single-source like Dijkstra).
- **Small Constraints:** Usually V (vertices) <= 400 or 500. (Kyunki O(V^3) complexity hoti hai, toh bade graphs pe TLE dega).
- **Negative Edge Weights:** Ye negative weights handle kar sakta hai (unlike Dijkstra), bas **negative weight cycle** nahi honi chahiye.
- **Transibility / Reachability:** Kya ek node se dusre node tak pahucha ja sakta hai ya nahi.


3. THE CODE STRUCTURE & THE #1 TRAP TO REMEMBER
--------------------------------------------------------------------------------
// 3 Nested Loops: 'k' MUST be the outermost loop!
for (int k = 0; k < V; k++) {          // Intermediate node
    for (int i = 0; i < V; i++) {      // Source node
        for (int j = 0; j < V; j++) {  // Destination node
            if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

⚠️ CRITICAL TRAP: 
Loop ki ordering bohot important hai! 
'k' (intermediate node) hamesha sabse bahar (outermost) hona chahiye. 
Agar 'i' ya 'j' bahar hua, toh DP states properly compute nahi hongi kyunki 
chote subproblems pehle solve nahi hue honge.


4. COMPLEXITY & EDGE CASES
--------------------------------------------------------------------------------
- Time Complexity  : O(V^3) -> 3 nested loops running V times.
- Space Complexity : O(V^2) -> 2D distance matrix store karne ke liye.

- How to detect Negative Weight Cycle?
  Algorithm run hone ke baad, agar kisi bhi node ke liye `dist[i][i] < 0` ho jaye, 
  iska matlab graph mein negative weight cycle present hai.
================================================================================
*/