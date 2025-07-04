class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> length(operations.size() + 1);
        length[0] = 1;

        for (int i = 0; i < operations.size(); ++i) {
            length[i + 1] = length[i] * 2;
            if (length[i + 1] > 1e18) {
                length[i + 1] = 1e18;
            }
        }

        int shift = 0;
        for (int i = operations.size() - 1; i >= 0; --i) {
            if (k > length[i]) {
                k -= length[i];
                if (operations[i] == 1) {
                    shift = (shift + 1) % 26;
                }
            }
        }

        char result = ((('a' - 'a') + shift) % 26) + 'a';
        return result;
    }
};
