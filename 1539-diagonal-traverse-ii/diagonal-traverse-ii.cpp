class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> mp ;
        int maxx = 0 ;
        
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            for ( int j = 0 ; j < nums[i].size() ; j++ ) {
                mp[i + j].push_back(nums[i][j]) ;
                maxx = max ( maxx , i + j ) ;
            }
        }

        vector<int> ans ;

        for ( int d = 0 ; d <= maxx ; d++ ) {
            vector<int> t = mp[d] ;

            for ( int i = t.size() - 1 ; i >= 0 ; i-- ) {
                ans.push_back(t[i]) ;
            }
        }

        return ans ;
    }
};