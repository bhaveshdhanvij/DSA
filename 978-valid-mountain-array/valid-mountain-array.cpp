class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        int n = a.size() ;
        if ( n < 3 ) return false ;

        int i = 0 ;
        while ( i + 1 < n && a[i] < a[i + 1] ) i++ ;

        // if never move forward or reached the end (edge case)
        if ( i == 0 || i == n - 1 ) return false ;

        while ( i + 1 < n && a[i] > a[i + 1] ) i++ ;

        return i == n - 1 ;
    }
};