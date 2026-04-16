class Solution {
public:
    vector<int> arrayChange(vector<int>& a, vector<vector<int>>& op) {
        unordered_map<int,int> mp ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            mp[a[i]] = i ;
        }

        for ( auto x : op ) {
            int old = x[0] ;
            int neww = x[1] ;

            int idx = mp[old] ;
            a[idx] = neww ;

            mp[neww] = idx ;
            mp.erase(old) ;
        }

        return a ;
    }
};