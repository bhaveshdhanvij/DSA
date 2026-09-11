class Solution {
public:
    int totalNumbers(vector<int>& a) {
        unordered_set<int> s ;
        int n = a.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( a[i] == 0 ) continue ;
            for ( int j = 0 ; j < n ; j++ ) {
                if ( j == i ) continue ;
                for ( int k = 0 ; k < n ; k++ ) {
                    if ( k == i || k == j ) continue ;
                    if ( a[k] % 2 != 0 ) continue ;
                    int x = a[i] * 100 + a[j] * 10 + a[k] ;
                    s.insert(x) ;
                }
            }
        }
        return s.size() ;
    }
};