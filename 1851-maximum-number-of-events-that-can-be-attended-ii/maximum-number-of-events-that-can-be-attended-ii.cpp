class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        vector<int> startTimes(n);
        for (int i = 0; i < n; ++i) {
            startTimes[i] = events[i][0];
        }

        auto findNext = [&](int endDay) {
            int low = 0, high = n;
            while (low < high) {
                int mid = (low + high) / 2;
                if (events[mid][0] > endDay)
                    high = mid;
                else
                    low = mid + 1;
            }
            return low;
        };

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                int nextIndex = findNext(events[i][1]);
                dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[nextIndex][j - 1]);
            }
        }

        return dp[0][k];
    }
};
