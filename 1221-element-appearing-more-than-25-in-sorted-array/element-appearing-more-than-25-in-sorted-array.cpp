class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
        int n = a.size() ;
        
        int c = 1 ;
        for ( int i = 1 ; i < n ; i++ ) {
            if ( a[i] == a[i - 1] ) c++ ;
            else c = 1 ;

            if ( c > n * 0.25 ) return a[i] ; 
        }

        return a[0] ;
    }
};