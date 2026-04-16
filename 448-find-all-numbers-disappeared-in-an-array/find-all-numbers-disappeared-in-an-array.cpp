class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        int n = a.size() ;
        unordered_map<int,int> mp ;
        for ( int x : a ) mp[x]++ ;

        vector<int> ans ;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( !mp.count(i) ) {
                ans.push_back(i) ;
            }
        }

        return ans ;
    }
};