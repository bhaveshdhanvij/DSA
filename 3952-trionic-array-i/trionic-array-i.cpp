class Solution {
public:
    bool isTrionic(vector<int>& a) {
        int n = a.size() ;
        int i = 0 ;

        while ( i + 1 < n && a[i] < a[i + 1] ) i++ ;

        if ( i == 0 || i == n - 1 ) return false ;

        while ( i + 1 < n && a[i] > a[i + 1] ) i++ ;

        if ( i == n - 1 ) return false ;

        while ( i + 1 < n && a[i] < a[i + 1] ) i++ ;

        return i == n - 1 ;
    }
};