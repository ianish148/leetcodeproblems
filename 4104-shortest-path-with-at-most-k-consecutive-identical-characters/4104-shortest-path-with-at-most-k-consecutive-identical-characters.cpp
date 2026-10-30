class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;

        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, node, cnt] = pq.top();
            pq.pop();

            if (cost > dist[node][cnt]) {
                continue;
            }

            if (node == n - 1) {
                return cost;
            }

            for (auto [next, wt] : adj[node]) {

                int newCnt = 1;

                if (labels[node] == labels[next]) {
                    newCnt = cnt + 1;
                }

                if (newCnt > k) {
                    continue;
                }

                long long newCost = cost + wt;

                if (newCost < dist[next][newCnt]) {

                    dist[next][newCnt] = newCost;

                    pq.push({newCost, next, newCnt});
                }
            }
        }

        return -1;
    }
};