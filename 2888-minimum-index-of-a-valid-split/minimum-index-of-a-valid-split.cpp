class Solution {
public:
    int minimumIndex(vector<int>& a) {
        int n = a.size() ;
        int d = -1 ;
        unordered_map<int,int> mp ;
        for ( int x : a ) mp[x]++ ;
        for ( auto p : mp ) {
            if ( p.second > n / 2 ) {
                d = p.first ;
            }
        }

        int c = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( a[i] == d ) {
                c++ ;
            }
            if ( (c > (i + 1) / 2) && ( (mp[d] - c) > (n - i - 1) / 2) ) return i ;
        }
        
        return -1 ;
    }
};