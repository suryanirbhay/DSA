class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            int width = r - l;
            int he = min(height[l], height[r]);
            int curwater = width * he;
            maxwater = max(maxwater, curwater);

            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxwater;
    }
};
