class Solution {
public:
    bool helper(vector<int>& a) {
        int curr = a[1] - a[0] ;
        for ( int i = 2 ; i < a.size() ; i++ ) {
            if ( a[i] - a[i - 1] != curr ) {
                return false ;
            }
        }
        return true ;
    }
    int countSpecialIntegers(vector<int>& a) {
        int n = a.size() ;
        unordered_map<int,vector<int>> mp ;
        for ( int i= 0 ; i < n; i++) {
            mp[a[i]].push_back(i) ;
        }
        int ans = 0 ;
        for ( auto p : mp ) {
            auto b = p.second ;
            if ( b.size() <= 2 ) continue ;
            if ( helper(b) ) ans++ ;
        }
        return ans ;
    }
};