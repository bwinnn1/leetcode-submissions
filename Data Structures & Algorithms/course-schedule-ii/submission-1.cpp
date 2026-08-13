class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses, 0);

        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            // b unlocks a
            adj[b].push_back(a);

            // increase the count of in degree a
            in_degree[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);

            // for each course that depends on this one. We can check using adjacency list
            for (int each : adj[course]) {
                in_degree[each]--;
                if (in_degree[each] == 0){
                    q.push(each);
                }
            }
        }

        // check if result size is smaller than numCourses
        if (result.size() == numCourses) {
            return result;
        } else {
            return {};
        }
    }
};
