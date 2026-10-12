class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(30, 0);
        for (int x : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((x >> i) & 1) {
                    bit_count[i]++;
                }
            }
        }

        long long ans = 0;
        long long mod = 1e9 + 7;

        for (int step = 0; step < k; ++step) {
            long long current_num = 0;
            for (int i = 0; i < 30; ++i) {
                if (bit_count[i] > 0) {
                    current_num |= (1 << i);
                    bit_count[i]--;
                }
            }
            ans = (ans + current_num * current_num) % mod;
        }

        return ans;
    }
};