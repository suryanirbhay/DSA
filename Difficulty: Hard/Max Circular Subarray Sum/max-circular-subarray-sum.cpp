class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        int maxKadane = arr[0];
        int currentMax = arr[0];
        int minKadane = arr[0];
        int currentMin = arr[0];

        for (int i = 1; i < arr.size(); ++i) {
            totalSum += arr[i];

            
            currentMax = max(arr[i], currentMax + arr[i]);
            maxKadane = max(maxKadane, currentMax);

           
            currentMin = min(arr[i], currentMin + arr[i]);
            minKadane = min(minKadane, currentMin);
        }

        totalSum += arr[0]; 

        if (totalSum == minKadane)
            return maxKadane;

        return max(maxKadane, totalSum - minKadane);
    }
};
