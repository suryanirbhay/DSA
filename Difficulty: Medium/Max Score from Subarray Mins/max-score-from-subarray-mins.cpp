class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,arr[i-1]+arr[i]);
        }
        return ans;
    }
};