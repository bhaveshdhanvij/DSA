class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans ;
        
        for ( int x : nums ) {
            if ( x != 2 ) {
                int l = x + 1 ;
                ans.push_back(x - (l & -l) / 2) ;
            }else {
                ans.push_back(-1) ;
            }
        }

        return ans ;
    }
};