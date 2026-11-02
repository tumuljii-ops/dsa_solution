class Solution:
    def largestSumCycle(self, edge):
        # code here
        
        
        n = len(edge)
        visited = [0] * n 
        max_sum = -1

        for i in range(n):
            if visited[i] == 0:
                current = i
                path = []

                while current != -1 and visited[current] == 0:
                    visited[current] = 1
                    path.append(current)
                    current = edge[current]

                if current != -1 and visited[current] == 1:
                    cycle_sum = 0
                    start_node = current

                    is_collecting = False

                    for node in path:
                        if node == start_node:
                            is_collecting = True

                        if is_collecting:
                            cycle_sum += node

                    if cycle_sum > max_sum:
                        max_sum = cycle_sum

                for node in path:
                    visited[node] = 2

        return max_sum