class Solution {
public:
    bool isGood(vector<int>& a) {
        int n = a.size() - 1 ;
        sort ( a.begin() , a.end() ) ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( i == a.size() - 1 || i == a.size() - 2 ) {
                if ( a[i] != n ) {
                    return false ;
                }
            }else {
                if ( a[i] != i + 1 ) {
                    return false ;
                }
            }
        }
        return true ;
    }
};