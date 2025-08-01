class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;
        
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = arr[st.top()];
            }
            st.push(i);
        }
        return res;
    }
};
