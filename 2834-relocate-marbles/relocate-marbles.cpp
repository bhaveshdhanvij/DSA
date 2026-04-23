class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> s(nums.begin(), nums.end());

        for (int i = 0; i < moveFrom.size(); i++) {
            if (s.erase(moveFrom[i])) {
                s.insert(moveTo[i]);
            }
        }

        vector<int> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};