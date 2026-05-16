class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        vector<int> flowergarden(n + 1);
        vector<int> vis(n + 1, 0);

        for (auto it : paths) {
            int s = it[0];
            int d = it[1];
            adj[s].push_back(d);
            adj[d].push_back(s);
        }

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                flowergarden[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto neighbor : adj[node]) {
                        if (!vis[neighbor]) {
                            // Find available colors for the neighbor
                            vector<int> col(5, 0);
                            for (auto i : adj[neighbor]) {
                                col[flowergarden[i]] = 1;
                            }

                            // Assign the first available color to the neighbor
                            for (int k = 1; k < 5; ++k) {
                                if (col[k] == 0) {
                                    flowergarden[neighbor] = k;
                                    break;
                                }
                            }

                            vis[neighbor] = 1;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        return vector<int>(flowergarden.begin() + 1, flowergarden.end());
    }
};