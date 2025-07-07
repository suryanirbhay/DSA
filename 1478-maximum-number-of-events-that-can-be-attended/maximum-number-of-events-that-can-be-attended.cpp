class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
    
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap; 

        int day = 1, i = 0, res = 0;
        int n = events.size();

        int lastDay = 0;
        for (auto& e : events)
            lastDay = max(lastDay, e[1]);

        while (day <= lastDay) {
            
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                i++;
            }

            
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

           
            if (!minHeap.empty()) {
                minHeap.pop();
                res++;
            }

            day++;
        }

        return res;
    }
};
