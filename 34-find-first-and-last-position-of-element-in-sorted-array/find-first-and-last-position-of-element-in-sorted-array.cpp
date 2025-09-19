class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result(2, -1);
    int n = nums.size();
    if (n == 0) return result;
    
   
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) right = mid - 1;
        else left = mid + 1;
        if (nums[mid] == target) result[0] = mid;
    }
    
    
    left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid - 1;
        if (nums[mid] == target) result[1] = mid;
    }
    
    return result;

    }
};