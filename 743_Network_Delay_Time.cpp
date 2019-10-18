https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> distant(N + 1, INT_MAX);
        distant[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (distant[u] != INT_MAX && distant[v] > distant[u] + w) {
                    distant[v] = distant[u] + w;
                }
            }
        }

        int timewait = 0;
        for (int i = 1; i <= N; i++)
            timewait = max(timewait, distant[i]);
        return timewait == INT_MAX ? -1 : timewait;
    }
};
