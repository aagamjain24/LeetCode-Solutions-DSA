class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Available rooms (smallest room number first)
        priority_queue<int, vector<int>, greater<int>> available;

        // Busy rooms -> {endTime, roomNumber}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        for (int i = 0; i < n; i++)
            available.push(i);

        vector<long long> cnt(n, 0);

        for (auto &meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // Free all rooms that have finished by current start time
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                // Assign immediately
                int room = available.top();
                available.pop();

                cnt[room]++;
                busy.push({end, room});
            } else {
                // Delay meeting until earliest room becomes free
                auto [finishTime, room] = busy.top();
                busy.pop();

                cnt[room]++;
                busy.push({finishTime + duration, room});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] > cnt[ans])
                ans = i;
        }

        return ans;
    }
};